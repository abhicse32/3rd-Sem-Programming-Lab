# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: newton-1 newton-2

newton-1: newton-1.o polynomial.o
	gcc $(LDFLAGS) $^ -o $@

newton-2: newton-2.o polynomial.o
	gcc $(LDFLAGS) $^ -o $@

newton-1.o: newton-1.c polynomial.h
	gcc -c $(CFLAGS) $< -o $@

newton-2.o: newton-2.c polynomial.h
	gcc -c $(CFLAGS) $< -o $@

polynomial.o: polynomial.c polynomial.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf newton-1 newton-2
	rm -rf tests/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test: all
	$(SH) tests/run_tests.sh

