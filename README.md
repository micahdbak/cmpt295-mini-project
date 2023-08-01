# CMPT 295 Mini-Project

This repository holds the source code for my CMPT 295 Mini-Project.

This project aims to answer the following question:
"do certain sorting algorithms have greater memory locality than others?"
I hope to answer this question by implementing the quick, heap, merge, insertion, selection, bubble, and bogo sorting algorithms in C.
Additionally, I will be implementing these sorting algorithms with no recursion whatsoever,
to ensure that the areas in memory accessed is more easily read.

To ensure that the data created correlates to each respective algorithm, the assembly output for a chosen optimization level
will be analyzed with respect to the C source code.
Any differences in algorithm implementation will be taken into account.

To minimize noise in the test data,
the program will create an array in memory linearly
using generated pseudo-random numbers.
