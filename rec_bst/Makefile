# Makefile
#

SH = bash
CC = gcc

main: bst_main.o \
	   	  bst.o
	$(CC) -o $@ $^

bst_main.o: bst_main.c \
			bst.h
	$(CC) -o $@ -c $<

bst.o: bst.c \
	   bst.h
	$(CC) -o $@ -c $<

test: main
	$(SH) tests/run_tests.sh

clean:
	rm -rf *.o
	rm -rf main
	rm -rf tests/*_
