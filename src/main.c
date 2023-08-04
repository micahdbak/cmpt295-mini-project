// main.c

#include "sorts.h"

#include <stdio.h> // printf
#include <stdlib.h> // atoi; srand; rand
#include <time.h> // time; struct timespec; clock_gettime

typedef void (*algor_t)(uint64_t *, uint64_t);

void randarr(uint64_t *arr, uint64_t length) {
	for (uint64_t i = 0; i < length; i++)
		arr[i] = rand() % UINT64_MAX;
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

static const char *progress = "-/|\\";

void test(const char *name, uint64_t *arr, uint64_t length, uint64_t ntests, algor_t algor) {
	uint64_t passed = 0;

	printf("%s: -", name);
	fflush(stdout);

	for (uint64_t i = 0; i < ntests; i++) {
		randarr(arr, length); // O(n)
		algor(arr, length); // O(n^2) or O(nlogn) or O(n!)
		passed += is_sorted(arr, length); // O(n)
		printf("\b%c", progress[passed%4]);
		fflush(stdout);
	}

	printf("\bpassed %lu of %lu.\n", passed, ntests);
}

void grind(const char *name, uint64_t *arr, uint64_t length, uint64_t ntests, algor_t algor) {
	struct timespec start, end;
	uint64_t passed = 0;

	printf("%s: -", name);
	fflush(stdout);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

	for (uint64_t i = 0; i < ntests; i++) {
		randarr(arr, length); // O(n)
		algor(arr, length); // O(n^2) or O(nlogn) or O(n!)
		printf("\b%c", progress[(++passed)%4]);
		fflush(stdout);
	}

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
	double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	printf("\b%.4fs to sort %lu arrays of size %lu; %.4fs average\n",
		elapsed, ntests, length, elapsed / (double)ntests);
}

#define DEFAULT_LENGTH  100
#define DEFAULT_NTESTS  100

#define USAGE\
	"$ sorts length ntests algor\n"\
	"(length): number of items per array\n"\
	"(ntests): number of tests to run per algorithm\n"\
	"(algor): algorithm to perform;\n"\
	"\t0: bogo sort\n"\
	"\t1: selection sort\n"\
	"\t2: insertion sort\n"\
	"\t3: shell sort\n"\
	"\t4: merge sort\n"\
	"\t5: quick sort\n"\
	"\t6: heap sort\n"\
	"----------------\n"

int main(int argc, char **argv) {
	uint64_t length = DEFAULT_LENGTH;
	uint64_t ntests = DEFAULT_NTESTS;
	uint64_t algor = 1; // selection sort

	if (argc > 1)
		length = atoi(argv[1]);
	if (argc > 2)
		ntests = atoi(argv[2]);
	if (argc > 3)
		algor = atoi(argv[3]);

	printf(USAGE "Using array length of %lu (%lukb); running %lu tests per algorithm.\n",
		length, (length*sizeof(uint64_t))/1024, ntests);

	srand(time(0));

	uint64_t *arr = (uint64_t *)malloc(sizeof(uint64_t) * length);
	algor_t algors[] = {
		bogos,
		selects,
		inserts,
		shells,
		merges,
		quicks,
		heaps
	};
	const char *names[] = {
		"bogo sort",
		"selection sort",
		"insertion sort",
		"shell sort",
		"merge sort",
		"quick sort",
		"heap sort"
	};

#ifdef TEST
	test("bogos", arr, length, ntests, bogos);
	test("selects", arr, length, ntests, selects);
	test("inserts", arr, length, ntests, inserts);
	test("shells", arr, length, ntests, shells);
	test("merges", arr, length, ntests, merges);
	test("quicks", arr, length, ntests, quicks);
	test("heaps", arr, length, ntests, heaps);
#else
	printf("----GRINDING----\n");
	grind(names[algor], arr, length, ntests, algors[algor]);
#endif

	free(arr);

	return 0;
}
