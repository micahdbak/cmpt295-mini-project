// queue.c

#include "sorts.h"

#include <string.h> // memcpy

// reference for struct queue
/*
struct queue {
	struct params {
		uint64_t *arr, length;
	} *params;
	uint64_t head, tail, capacity;
}
*/

void make_queue(struct queue *queue, size_t item_size, uint64_t capacity) {
	queue->items = (uint8_t *)malloc(item_size*capacity);
	queue->item_size = item_size;
	queue->capacity = capacity;
	queue->head = queue->tail = 0;
}

void free_queue(struct queue *queue) {
	free(queue->items);
	queue->items = NULL;
}

void grow_queue(struct queue *queue, uint64_t capacity) {
	queue->items = (uint8_t *)realloc(queue->items, queue->item_size*capacity);

	// reduce occupied space
	if (queue->head > 0) {
		// shift everything left
		memcpy(
			// destination is at first byte
			queue->items,
			// source is head items in
			queue->items + queue->item_size*queue->head,
			// number of items is item_size * difference between head and time
			queue->item_size * (queue->tail - queue->head)
		);
		queue->tail -= queue->head;
		queue->head = 0; // reset head to 0
	}

	queue->capacity = capacity;
}

void enqueue(struct queue *queue, const void *item) {
	if (queue->tail >= queue->capacity)
		grow_queue(queue, queue->capacity*2);

	memcpy(
		// location to insert new item
		queue->items + queue->item_size*queue->tail,
		item, // src is provided item
		queue->item_size // number of bytes is item_size
	);
	queue->tail++;
}

bool dequeue(struct queue *queue, void *item) {
	if (queue->head >= queue->tail)
		return false;

	memcpy(
		item, // dst is provided item
		// location of item wanted
		queue->items + queue->item_size*queue->head,
		queue->item_size // number of bytes is item_size
	);
	queue->head++;

	return true;
}

