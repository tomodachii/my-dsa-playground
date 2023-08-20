#include <stdio.h>
#include <stdlib.h>

#include "insertion_sort_recursive.h"

void insertion_sort_recursive(int *A, int size) {
    if (size <= 0) return;
    // Recursive call to reach the case where size = 1 -> A[0]
    insertion_sort_recursive(A, size - 1);
    int key = A[size - 1];
    int j = size - 2;
    while (j >= 0 && A[j] > key) {
        A[j + 1] = A[j];
        j = j - 1;
    }
    A[j + 1] = key;
}
