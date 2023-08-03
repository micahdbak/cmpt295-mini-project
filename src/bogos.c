// bogos.c

#include "sorts.h"

#include <stdio.h>

void bogos(uint64_t *arr, uint64_t length) {
	while (!is_sorted(arr, length)) {
		for (uint64_t i = 1; i < length-1; i++) {
			uint64_t j = i + (rand() % length-i);
			swap(arr, i-1, j);
		}
	}
}
