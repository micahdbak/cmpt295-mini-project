CFLAGS = -Wall -Wpedantic -Wextra -std=c17 -march=haswell -O3

bin:
	mkdir -p bin

sorts: bin src/*.c
	rm -f bin/sorts
	gcc $(CFLAGS) src/*.c -o bin/sorts
