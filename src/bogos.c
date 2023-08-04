// bogos.c

#include "sorts.h"

#include <stdio.h>

void bogos(uint64_t *arr, uint64_t length) {
	while (!is_sorted(arr, length)) {
		for (uint64_t i = 0; i < length; i++) {
			uint64_t tmp = arr[i];
			uint64_t j = rand() % length;
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
}
