// quicks.c

#include "sorts.h" // stdint, stdbool, stdlib

#include <stdio.h>

struct params {
	uint64_t start, end;
};

// quick sort algorithm
void quicks(uint64_t *arr, uint64_t length) {
	struct queue Q;
	struct params params;
	make_queue(&Q, sizeof(struct params), length);

	params.start = 0;
	params.end = length;

	do {
		if (params.end <= params.start)
			continue;

		// partition subarray
		uint64_t mid = params.start + (params.end - params.start)/2;
		uint64_t end = params.end;
		// params' useful data is used; now we can overwrite it

		// queue left portion
		// params.start
		params.end = mid;
		enqueue(&Q, &params);

		// queue right portion
		params.start = mid + 1;
		params.end = end;
		enqueue(&Q, &params);
	}
	while (dequeue(&Q, &params));

	printf("\tstats: %lu items, %lu capacity (%lukb).\n", Q.tail - Q.head, Q.capacity, (Q.capacity*Q.item_size)/1024);
	free_queue(&Q);
}
