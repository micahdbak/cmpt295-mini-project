CFLAGS = -Wall -Wpedantic -Wextra -std=c17 -march=haswell -O3

bin:
	mkdir -p bin

qsortc: bin src/main.c src/qsort.c
	rm -f bin/qsortc
	gcc $(CFLAGS) src/qsort.c -D QSORT=qsortc src/main.c -o bin/qsortc
