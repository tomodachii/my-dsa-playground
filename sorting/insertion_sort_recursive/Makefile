CC=c99
CFLAGS=-g3 -Wall

all: insertion_sort_recursive.out

test_insertion_sort_recursive.out: test_insertion_sort_recursive.o insertion_sort_recursive.o
	$(CC) $(CFLAGS) -o $@ $^

test: test_insertion_sort_recursive.out
	./test_insertion_sort_recursive.out

# these rules say to rebuild test_insertion_sort_recursive.o and insertion_sort_recursive.o if insertion_sort_recursive.h changes
main.o: test_insertion_sort_recursive.c insertion_sort_recursive.h
insertion_sort_recursive.o: insertion_sort_recursive.c insertion_sort_recursive.h

clean:
	$(RM) -f *.o *.out