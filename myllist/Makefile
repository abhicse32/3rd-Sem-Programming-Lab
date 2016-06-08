# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

main: main.o LList.o
	gcc $(LDFLAGS) $^ -o $@

all: main TOH

TOH: TOH.o LList.o
	gcc $(LDFLAGS) $^ -o $@

main.o: main.c LList.h
	gcc -c $(CFLAGS) $< -o $@

TOH.o: TOH.c LList.h
	gcc -c $(CFLAGS) $< -o $@

LList.o: LList.c LList.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf main
	rm -rf TOH
	rm -rf tests/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test: main
	$(SH) tests/run_tests.sh

