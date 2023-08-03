// quads.c
// ; quadratic sorting algorithms

#include "sorts.h"

void selects(uint64_t *arr, uint64_t length) {
	for (uint64_t i = 0; i < length - 1; i++) {
		uint64_t least = i;

		for (uint64_t j = i + 1; j < length; j++) {
			if (arr[j] < arr[least])
				least = j;
		}

		if (least != i)
			swap(arr, least, i);
	}
}

void inserts(uint64_t *arr, uint64_t length) {
	for (uint64_t i = 1; i < length; i++) {
		for (uint64_t j = i; j > 0 && arr[j - 1] > arr[j]; j--)
			swap(arr, j - 1, j);
	}
}

void shells(uint64_t *arr, uint64_t length) {
	static const uint64_t ngaps = 8;
	static const uint64_t gaps[] = { 701, 301, 132, 57, 23, 10, 4, 1 };

	for (uint64_t gap = 0; gap < ngaps; gap++) {
		for (uint64_t i = gaps[gap]; i < length; i++) {
			uint64_t tmp = arr[i];
			uint64_t j = i;

			while (j >= gaps[gap] && arr[j - gaps[gap]] > tmp) {
				arr[j] = arr[j - gaps[gap]];
				j -= gaps[gap];
			}

			arr[j] = tmp;
		}
	}
}
