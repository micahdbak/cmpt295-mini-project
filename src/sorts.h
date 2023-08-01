// sorts.h

#ifndef SORTS_H
#define SORTS_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

// queue

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

// general functions

void printarr(uint64_t *arr, uint64_t length);

// quick sort
void quicks(uint64_t *arr, uint64_t length);

#endif
