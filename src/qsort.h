// qsort.h

#ifndef QSORT_H
#define QSORT_H

#include <stdint.h>

// fill array with random values
void randarr(uint64_t *arr, uint64_t length, uint64_t maxval);
// print array contents
void printarr(uint64_t *arr, uint64_t length);

// std library implementation
void qsortstd(uint64_t *arr, uint64_t length);
// C implementation
void qsortc(uint64_t *arr, uint64_t length);
// C++ implementation
//void qsortcpp(uint64_t *arr, uint64_t length);
// x86 implementation (branched, branchless)
//void qsortx86(uint64_t *arr, uint64_t length);

#endif
