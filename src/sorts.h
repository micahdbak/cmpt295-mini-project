// sorts.h

#ifndef SORTS_H
#define SORTS_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define swap(_arr, _i, _j) {\
	uint64_t tmp = _arr[_i];\
	_arr[_i] = _arr[_j];\
	_arr[_j] = tmp;\
}

// stacks

struct stack {
	uint8_t *items;
	size_t item_size;
	uint64_t top, capacity;
};

void make_stack(struct stack *stack, size_t item_size, uint64_t capacity);
void free_stack(struct stack *stack);
void grow_stack(struct stack *stack, uint64_t new_size);
void push(struct stack *stack, const void *item);
bool pop(struct stack *stack, void *item);

// queues

struct queue {
	uint8_t *items;
	size_t item_size;
	uint64_t head, tail, capacity;
};

#define QUEUE_INITIAL_SIZE  100

void make_queue(struct queue *queue, size_t item_size, uint64_t capacity);
void free_queue(struct queue *queue);
void grow_queue(struct queue *queue, uint64_t new_size);
void enqueue(struct queue *queue, const void *item);
bool dequeue(struct queue *queue, void *item);

// additional functions

uint64_t is_sorted(uint64_t *arr, uint64_t length);
void printarr(uint64_t *arr, uint64_t length);

// quadratic sorting algorithms
// selection sort; insertion sort; shell sort (quads.c)
void selects(uint64_t *arr, uint64_t length);
void inserts(uint64_t *arr, uint64_t length);
void shells(uint64_t *arr, uint64_t length);

// bogo sort (bogos.c)
void bogos(uint64_t *arr, uint64_t length);

// nlogn sorting algorithms
// heap sort (heaps.c)
void heaps(uint64_t *arr, uint64_t length);
// merge sort (merges.c)
void merges(uint64_t *arr, uint64_t length);
// quick sort (quicks.c)
void quicks(uint64_t *arr, uint64_t length);

#endif
