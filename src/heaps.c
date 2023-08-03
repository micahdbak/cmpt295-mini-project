// heaps.c

#include "sorts.h"

#define PARENT(_i)  ((_i-1)/2)
#define LCHILD(_i)  ((2*_i)+1)
#define RCHILD(_i)  ((2*_i)+2)

void bubble_down(uint64_t *arr, uint64_t length, uint64_t i) {
	// bubble down
	while (i < length) {
		uint64_t c;

		if (LCHILD(i) >= length)
			break;
		else
		if (RCHILD(i) >= length)
			c = LCHILD(i);
		else
			c = arr[LCHILD(i)] > arr[RCHILD(i)]
				? LCHILD(i) : RCHILD(i);

		if (arr[c] > arr[i]) {
			swap(arr, i, c);
			i = c;
		} else
			break;
	}
}

void heaps(uint64_t *arr, uint64_t length) {
	// heapify
	for (int64_t i = (length-2)/2; i >= 0; i--)
		bubble_down(arr, length, i);

	for (uint64_t i = length - 1; i > 0; i--) {
		swap(arr, 0, i); // swap root of heap with end of array
		bubble_down(arr, i, 0); // bubble new root down
	}
}
