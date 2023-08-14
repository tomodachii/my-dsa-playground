CC=c99
CFLAGS=-g3 -Wall

all: merge_sort.out

test_merge_sort.out: test_merge_sort.o merge_sort.o
	$(CC) $(CFLAGS) -o $@ $^

test: test_merge_sort.out
	./test_merge_sort.out

# these rules say to rebuild test_merge_sort.o and merge_sort.o if merge_sort.h changes
main.o: test_merge_sort.c merge_sort.h
merge_sort.o: merge_sort.c merge_sort.h

clean:
	$(RM) -f *.o *.out