// main.c

#include "sorts.h"

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

uint64_t is_sorted(uint64_t *arr, uint64_t length) {
	for (uint64_t i = 0; i < length - 1; i++) {
		if (arr[i] > arr[i + 1])
			return 0;
	}

	return 1;
}

#define NTESTS (uint64_t)100

void test(const char *name, uint64_t length, uint64_t maxval, void (*algor)(uint64_t *, uint64_t)) {
	uint64_t *arr = (uint64_t *)malloc(sizeof(uint64_t) * length);
	uint64_t passed = 0;

	printf("%s: *", name);
	fflush(stdout);

	for (uint64_t i = 0; i < NTESTS; i++) {
		randarr(arr, length, maxval);
		algor(arr, length);
		passed += is_sorted(arr, length);
	}

	printf("\bpassed %lu of %lu.\n", passed, NTESTS);
	free(arr);
}

#define DEFAULT_LENGTH  100
#define DEFAULT_MAXVAL  1000

int main(int argc, char **argv) {
	uint64_t length = DEFAULT_LENGTH;
	uint64_t maxval = DEFAULT_MAXVAL;

	if (argc > 1) {
		length = atoi(argv[1]);

		if (argc == 3)
			maxval = atoi(argv[2]);
	}

	printf("Using array length of %lu (%lukb), with maximum value %lu; running %lu tests per algorithm.\n",
		length, (length*sizeof(uint64_t))/1024, maxval, NTESTS);

	srand(time(0));
	//test("bogos", length, maxval, bogos);
	test("selects", length, maxval, selects);
	test("inserts", length, maxval, inserts);
	test("shells", length, maxval, shells);
	test("merges", length, maxval, merges);
	test("quicks", length, maxval, quicks);
	test("heaps", length, maxval, heaps);

	return 0;
}
