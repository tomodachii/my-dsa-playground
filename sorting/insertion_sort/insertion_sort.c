#include "insertion_sort.h"

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *A, int size) {
    for (int i = 1; i < size; i++) {
        int key = A[i];
        // Insert A[i] to the sorted subarray A[0:i - 1]
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}
