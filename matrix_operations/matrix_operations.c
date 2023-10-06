#include "matrix_operations.h"

#include <stdio.h>
#include <stdlib.h>

#include "matrix_utils.h"

void square_matrix_add(int **A, int **B, int **C, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void square_matrix_multiply(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;  // Initialize the value of C[i][j]
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void square_matrix_multiply_recursive(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = 0; // ensure that the initial value of C[0][0] is 0
        C[0][0] += A[0][0] * B[0][0];
        return;
    }
    int **A11 = allocate_matrix(n / 2, n / 2);
    int **A12 = allocate_matrix(n / 2, n / 2);
    int **A21 = allocate_matrix(n / 2, n / 2);
    int **A22 = allocate_matrix(n / 2, n / 2);
    int **B11 = allocate_matrix(n / 2, n / 2);
    int **B12 = allocate_matrix(n / 2, n / 2);
    int **B21 = allocate_matrix(n / 2, n / 2);
    int **B22 = allocate_matrix(n / 2, n / 2);
    int **C11 = allocate_matrix(n / 2, n / 2);
    int **C12 = allocate_matrix(n / 2, n / 2);
    int **C21 = allocate_matrix(n / 2, n / 2);
    int **C22 = allocate_matrix(n / 2, n / 2);
    int **temp1 = allocate_matrix(n / 2, n / 2);
    int **temp2 = allocate_matrix(n / 2, n / 2);

    // Divide A, B, and C into submatrices
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n / 2];
            A21[i][j] = A[i + n / 2][j];
            A22[i][j] = A[i + n / 2][j + n / 2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + n / 2];
            B21[i][j] = B[i + n / 2][j];
            B22[i][j] = B[i + n / 2][j + n / 2];
        }
    }

    square_matrix_multiply_recursive(A11, B11, temp1, n / 2);
    square_matrix_multiply_recursive(A12, B21, temp2, n / 2);
    square_matrix_add(temp1, temp2, C11, n / 2);

    square_matrix_multiply_recursive(A11, B12, temp1, n / 2);
    square_matrix_multiply_recursive(A12, B22, temp2, n / 2);
    square_matrix_add(temp1, temp2, C12, n / 2);

    square_matrix_multiply_recursive(A21, B11, temp1, n / 2);
    square_matrix_multiply_recursive(A22, B21, temp2, n / 2);
    square_matrix_add(temp1, temp2, C21, n / 2);

    square_matrix_multiply_recursive(A21, B12, temp1, n / 2);
    square_matrix_multiply_recursive(A22, B22, temp2, n / 2);
    square_matrix_add(temp1, temp2, C22, n / 2);

    // Combine the submatrices into C
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            C[i][j] = C11[i][j];
            C[i][j + n / 2] = C12[i][j];
            C[i + n / 2][j] = C21[i][j];
            C[i + n / 2][j + n / 2] = C22[i][j];
        }
    }

    free(A11);
    free(A12);
    free(A21);
    free(A22);
    free(B11);
    free(B12);
    free(B21);
    free(B22);
    free(C11);
    free(C12);
    free(C21);
    free(C22);
    free(temp1);
    free(temp2);
}


