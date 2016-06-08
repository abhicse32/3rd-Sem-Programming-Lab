# Makefile
#

CC = gcc
SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: quicksort mergesort selectionsort insertionsort

plot: graph.plot
	gnuplot graph.plot

mergesort: msort.o mergesort.o
	gcc $(LDFLAGS) $^ -o $@

quicksort: qsort.o quicksort.o
	gcc $(LDFLAGS) $^ -o $@

insertionsort: isort.o insertionsort.o
	gcc $(LDFLAGS) $^ -o $@

selectionsort: ssort.o selectionsort.o
	gcc $(LDFLAGS) $^ -o $@



msort.o: sort.c mergesort.h
	gcc -c -DMERGESORT $(CFLAGS) $< -o $@

qsort.o: sort.c quicksort.h
	gcc -c -DQUICKSORT $(CFLAGS) $< -o $@

isort.o: sort.c insertionsort.h
	gcc -c -DINSERTIONSORT $(CFLAGS) $< -o $@

ssort.o: sort.c selectionsort.h
	gcc -c -DSELECTIONSORT $(CFLAGS) $< -o $@



mergesort.o: mergesort.c mergesort.h
	gcc -c $(CFLAGS) $< -o $@

quicksort.o: quicksort.c quicksort.h
	gcc -c $(CFLAGS) $< -o $@

insertionsort.o: insertionsort.c insertionsort.h
	gcc -c $(CFLAGS) $< -o $@

selectionsort.o: selectionsort.c selectionsort.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf tests/*_
	rm -rf quicksort mergesort insertionsort selectionsort

lint:

test: all
	$(SH) tests/run_tests.sh

