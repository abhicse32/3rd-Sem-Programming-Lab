# Makefile
#

CC = gcc
SH = bash
CFLAGS = -g
LDFLAGS = -lm


all: mazesolver

mazesolver: mazesolver.o main.o
	gcc $(LDFLAGS) $^ -o $@

mazesolver.o: MazeSolver.c MazeSolver.h
	gcc -c $(CFLAGS) $< -o $@

main.o: main.c MazeSolver.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf tests/*_
	rm -rf mazesolver

lint:

test: all
	$(SH) tests/run_tests.sh

