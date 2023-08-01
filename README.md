# CMPT 295 Mini-Project

This repository holds the source code for my CMPT 295 Mini-Project.

Some factors that this project is going to observe:
- How the C compiler optimizes the QuickSort algorithm.
- How choosing a pivot location effects cache-misses.

To observe these factors, the QuickSort algorithm will be implemented as:
- x86-64 Assembly (no branches)
- x86-64 Assembly (branched)
- C implementation
- C++ implementation

Additionally, the output assembly code of the C implementation will be
compared with the several assembly implementations created by myself.

To minimize noise in the test data,
the program will create an array in memory linearly
using generated pseudo-random numbers.
