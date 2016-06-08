# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

P5: P5.o Queue.o Stack.o
	gcc $(LDFLAGS) $^ -o $@

all:P5

P5.o: P5.c Queue.h Stack.h
	gcc -c $(CFLAGS) $< -o $@

Queue.o: Queue.c Queue.h
	gcc -c $(CFLAGS) $< -o $@
Stack.o: Stack.c Stack.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf P5
	rm -rf test/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test:P5
	$(SH) test/run_tests.sh

