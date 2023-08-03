// quicks.c

#include "sorts.h"

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
		// a single element can neither be split nor sorted; it is already sorted
		if (params.end <= params.start || params.end-params.start <= 1)
			continue;

		// use last item as pivot
		uint64_t pivot = arr[params.end-1];
		int64_t i = params.start, j = params.end-2;

		while (i <= j) {
			while (i <= j && arr[i] <= pivot)
				i++;
			while (j >= i && arr[j] >= pivot)
				j--;

			if (i < j) {
				uint64_t tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}

		uint64_t tmp = arr[i];
		arr[i] = pivot;
		arr[params.end-1] = tmp;
		// i is the location of the pivot;
		// params.start <= i <= params.end

		// keep track of params.end
		uint64_t end = params.end;

		// queue left portion
		// params.start remains the same
		params.end = i;
		enqueue(&Q, &params);

		// queue right portion
		params.start = i+1;
		params.end = end;
		enqueue(&Q, &params);
	}
	while (dequeue(&Q, &params));

	free_queue(&Q);
}
