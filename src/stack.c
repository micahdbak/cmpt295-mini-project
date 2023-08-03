// stack.c

#include "sorts.h"

#include <string.h> // memcpy

/*
struct stack {
	uint8_t *items;
	size_t item_size;
	uint64_t top, capacity;
};
*/

void make_stack(struct stack *stack, size_t item_size, uint64_t capacity) {
	stack->items = (uint8_t *)malloc(item_size*capacity);
	stack->item_size = item_size;
	stack->capacity = capacity;
	stack->top = 0;
}

void free_stack(struct stack *stack) {
	free(stack->items);
	stack->items = NULL;
}

void grow_stack(struct stack *stack, uint64_t capacity) {
	stack->items = (uint8_t *)realloc(stack->items, stack->item_size*capacity);
	stack->capacity = capacity;
}

void push(struct stack *stack, const void *item) {
	if (stack->top >= stack->capacity)
		grow_stack(stack, stack->capacity*2);

	memcpy(
		// location to insert new item
		stack->items + stack->item_size*stack->top,
		item, // src is provided item
		stack->item_size // number of bytes is item_size
	);
	stack->top++;
}

bool pop(struct stack *stack, void *item) {
	if (stack->top <= 0)
		return false;

	memcpy(
		item, // dst is provided item
		// location of item wanted
		stack->items + stack->item_size*(stack->top-1),
		stack->item_size // number of bytes is item_size
	);
	stack->top--;

	return true;
}

