#include "merge_sort_recursive.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *array_concat_i(int *A, int m, int *B, int n) {
  int *total = (int *)malloc((m + n) * sizeof(int));

  if (m > 0) {
    memcpy(total, A, m * sizeof(int));
  }
  
  if (n > 0) {
    memcpy(total + m, B, n * sizeof(int));
  }
  
  return total;
}

int *array_shift_i(int *A, int n) {
  if (n == 0)
  {
    return NULL;
  }

  int *result = (int *)malloc((n) * sizeof(int));
  memcpy(result, A + 1, (n) * sizeof(int));
  return result;
}

int *merge_recursive(int *L, int n_l, int *R, int n_r) {
  int n = n_l + n_r; 
  if (n_r == 0)
  {
    return L;
  }
  else if (n_l == 0)
  {
    return R;
  }
  int * result;
  if (L[0] < R[0])
  {
    int* head = (int *)malloc(sizeof(int));
    memcpy(head, L, sizeof(int));
    result = array_concat_i(head, 1, merge_recursive(array_shift_i(L, n_l - 1), n_l - 1, R, n_r), n - 1);
  }
  else
  {
    int *head = (int *)malloc(sizeof(int));
    memcpy(head, R, sizeof(int));
    result = array_concat_i(head, 1, merge_recursive(L, n_l, array_shift_i(R, n_r - 1), n_r - 1), n - 1);
  }
  return result;
}

int *merge_sort_recursive(int *A, int p, int r)
{
  if (p >= r)
  {
    int *head = (int *)malloc(sizeof(int));
    *head = A[r];
    return head;
  }
  int q = (p + r) / 2;
  int l = r - p + 1;

  // Merge A[p:q] and A[q + 1:r] into A[p:r]
  return merge_recursive(merge_sort_recursive(A, p, q), l - l / 2, merge_sort_recursive(A, q + 1, r), l / 2);
}