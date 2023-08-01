CFLAGS = -Wall -Wpedantic -Wextra -std=c17 -march=haswell -O3

bin:
	mkdir -p bin

.PHONY: c
c: bin src/qs.c src/main.c
	rm -f bin/qs_c
	gcc $(CFLAGS) src/qs.c -D QS_C src/main.c -o bin/qs_c
