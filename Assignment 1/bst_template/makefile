CC = gcc

main.out: bst_main.o \
	   	  bst.o
	$(CC) -o $@ $^

bst_main.o: bst_main.c \
			bst.h
	$(CC) -o $@ -c $<

bst.o: bst.c \
	   bst.h
	$(CC) -o $@ -c $<

clean :
		rm -rf *.o *.out
