#include "insertion_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int A[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(A) / sizeof(A[0]);

    // Measure the start time
    clock_t start_time = clock();

    insertion_sort(A, size);

    // Measure the end time
    clock_t end_time = clock();

    // Calculate the elapsed time in seconds
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Time taken: %.6f seconds\n", elapsed_time);

    return 0;
}
