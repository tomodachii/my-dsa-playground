#include "merge_sort.h"

#include <stdio.h>
#include <stdlib.h>

void merge(int *A, int p, int q, int r) {
    int n_l = q - p + 1;  // length of A[p:q]
    int n_r = r - q;      // length of A[q + 1:r]
    int *L = (int *)malloc(n_l * sizeof(int));
    int *R = (int *)malloc(n_r * sizeof(int));
    // copy A[p:q] into L[0:n_l - 1]
    for (int i = 0; i < n_l; i++) {
        L[i] = A[p + i];
    }
    // copy A[q + 1:r] into R[0:n_r - 1]
    for (int j = 0; j < n_r; j++) {
        R[j] = A[q + j + 1];
    }
    int i = 0;  // i indexes the smallest remaining element in L
    int j = 0;  // j indexes the smallest remaining element in R
    int k = p;  // k indexes the location in A to fill
    // A[p:r] divided from A[0:n] -> p indexes the item that need to be filled

    // As long as each of the arrays L and R contains an unmerged element,
    // copy the smallest unmerged element back into A[p:r]
    while (i < n_l && j < n_r) {
        // Since L[i] is the smallest element remaining in L and R[j] is the
        // smallest element remaining in R and both L and R are sorted,
        // the smaller one will be merged into A[p:r] first!
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
    }
    // Having gone through one of L and R entirely, copy the
    // remainder of the other to the end of A[p:r]
    while (i < n_l) {
        A[k] = L[i];
        i = i + 1;
        k = k + 1;
    }
    while (j < n_r) {
        A[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
}

void merge_sort(int *A, int p, int r) {
    if (p >= r) {
        return;
    }
    int q = (p +r) / 2;
    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);
    // Merge A[p:q] and A[q + 1:r] into A[p:r]
    merge(A, p, q, r);
}