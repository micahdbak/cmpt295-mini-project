// merges.c

#include "sorts.h"

void merges(uint64_t *arr, uint64_t length) {
	uint64_t merged[length]; // space-complexity is O(n)

	for (uint64_t size = 1; size <= length; size *= 2) {
		for (uint64_t start = 0; start < length; start += 2*size) {
			uint64_t mid = start + size;
			mid = mid > length ? length : mid;
			uint64_t end = start + 2*size;
			end = end > length ? length : end;

			uint64_t i, j, k; // i: left; j: right; k: merged

			i = start;
			j = mid;
			k = 0;

			while (i < mid && j < end) {
				if (arr[i] <= arr[j])
					merged[k++] = arr[i++];
				else
					merged[k++] = arr[j++];
			}

			while (i < mid)
				merged[k++] = arr[i++];
			while (j < end)
				merged[k++] = arr[j++];

			// copy merged to proper place in array
			for (i = 0; i < k; i++)
				arr[start+i] = merged[i];
		}
	}
}
