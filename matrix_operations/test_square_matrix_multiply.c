#include "matrix_operations.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int n; // Size of matrices (assumed to be square)
    printf("Enter the size of matrices: ");
    scanf("%d", &n);

    // int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int **A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
    }

    int **B = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        B[i] = (int *)malloc(n * sizeof(int));
    }

    int **C = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        C[i] = (int *)malloc(n * sizeof(int));
    }

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

    square_matrix_multiply(A, B, C, n);

    printf("Resultant matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}