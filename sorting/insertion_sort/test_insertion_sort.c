#include "insertion_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void test_insertion_sort(int A[], const char *case_name) {
    int A_solution[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 9, 10, 15};
    int size = sizeof(A_solution) / sizeof(A_solution[0]);

    printf("%s\n", case_name);
    printf(" - Unsorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }

    // Measure the start time
    clock_t start_time = clock();

    insertion_sort(A, size);

    // Measure the end time
    clock_t end_time = clock();

    // Calculate the elapsed time in seconds
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n - Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    for (int i = 0; i < size; i++) {
        assert(A[i] == A_solution[i]);
    }

    printf(" - %s Time taken: %.8f seconds\n", case_name, elapsed_time);
}

int main()
{
    printf("Insertion sort Test Drive");
    int A_average_case[] = {5, 2, 9, 1, 5, 6, 8, 10, 7, 3, 4, 15, 9};
    int A_best_case[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 9, 10, 15};
    int A_worst_case[] = {15, 10, 9, 9, 8, 7, 6, 5, 5, 4, 3, 2, 1};
    test_insertion_sort(A_average_case, "Average Case");
    test_insertion_sort(A_best_case, "Best Case");
    test_insertion_sort(A_worst_case, "Worst Case");

    return 0;
}
