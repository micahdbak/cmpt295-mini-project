#include "qsort.h"

#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(uint64_t *)a - *(uint64_t *)b;
}

void qsortstd(uint64_t *arr, uint64_t length) {
	qsort(arr, length, sizeof(uint64_t), cmp);
}

void qsortc(uint64_t *arr, uint64_t length) {
	qsortstd(arr, length);
}
