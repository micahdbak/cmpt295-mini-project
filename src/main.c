#include "qs.h"

#include <stdio.h> // printf
#include <stdlib.h> // atoi

#define DEFAULT_LENGTH  100

int main(int argc, char **argv) {
	uint64_t length = DEFAULT_LENGTH;

	if (argc > 1)
		// read length from argument
		length = atoi(argv[1]);

	printf("Using array length of %lu.\n", length);

#ifdef QS_C
	qs_c(NULL, length);
#endif

	return 0;
}
