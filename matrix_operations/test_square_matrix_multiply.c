#include "matrix_operations.h"
#include "matrix_utils.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int n; // Size of matrices (assumed to be square)
    printf("Enter the size of matrices: ");
    scanf("%d", &n);

    int **A = allocate_matrix(n, n);
    int **B = allocate_matrix(n, n);
    int **C = allocate_matrix(n, n);

    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    square_matrix_multiply_recursive(A, B, C, n);
    // square_matrix_add(A, B, C, n);

    printf("Resultant matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}