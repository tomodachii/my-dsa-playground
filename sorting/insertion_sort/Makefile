CC=c99
CFLAGS=-g3 -Wall

all: insertion_sort.out

test_insertion_sort.out: test_insertion_sort.o insertion_sort.o
	$(CC) $(CFLAGS) -o $@ $^

test: test_insertion_sort.out
	./test_insertion_sort.out

# these rules say to rebuild test_insertion_sort.o and insertion_sort.o if insertion_sort.h changes
main.o: test_insertion_sort.c insertion_sort.h
insertion_sort.o: insertion_sort.c insertion_sort.h

clean:
	$(RM) -f *.o *.out