#include "qsort.h"

#include <stdio.h> // printf
#include <stdlib.h> // atoi; srand; rand
#include <time.h> // time

void randarr(uint64_t *arr, uint64_t length, uint64_t maxval) {
	for (uint64_t i = 0; i < length; i++)
		arr[i] = rand() % maxval;
}

void printarr(uint64_t *arr, uint64_t length) {
	for (uint64_t i = 0; i < length; i++)
		printf("%lu%c", arr[i], i == length - 1 ? '\n' : ' ');
}

#define DEFAULT_LENGTH  100
#define DEFAULT_MAXVAL  1000

int main(int argc, char **argv) {
	uint64_t *arr = NULL;
	uint64_t length = DEFAULT_LENGTH;
	uint64_t maxval = DEFAULT_MAXVAL;

	if (argc > 1) {
		length = atoi(argv[1]);

		if (argc == 3)
			maxval = atoi(argv[2]);
	}

	printf("Using array length of %lu, with maximum value %lu.\n", length, maxval);

	srand(time(0));
	arr = (uint64_t *)malloc(sizeof(uint64_t) * length);
	randarr(arr, length, maxval);

	printf("---- BEGIN TEST ----\n");
	printf("---- Array before:\n");
	printarr(arr, length);

#ifndef QSORT
	// by default, use C implementation
	qsortc(arr, length);
#else
	// QSORT is a macro that expands to the function to use
	QSORT(arr, length);
#endif

	printf("---- Array after:\n");
	printarr(arr, length);
	printf("---- END TEST ----\n");

	free(arr);

	return 0;
}
