#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "merge_sort_recursive.h"

int *array_concat_i_2(int *A, int m, int *B, int n)
{
  printf("m + n = %d\n", m + n);
  int *total = (int *)malloc((m + n) * sizeof(int));

  if (m > 0)
  {
    memcpy(total, A, m * sizeof(int));
  }

  if (n > 0)
  {
    memcpy(total + m, B, n * sizeof(int));
  }

  return total;
}

int *array_shift_i2(int *A, int n)
{
  if (n == 0)
  {
    return NULL;
  }
  int *result = (int *)malloc((n - 1) * sizeof(int));
  memcpy(result, A + 1, (n - 1) * sizeof(int));
  return result;
}

int main(void)
{
  int *A, *B, n, i;
  printf("Enter Array size: ");
  scanf("%d", &n);
  if (n <= 0) /* exit program if arraysize is not greater than 0 */
  {
    printf("Array size must be Greater than 0!\n");
    return 1;
  }
  A = (int *)malloc(n * sizeof(int));
  B = (int *)malloc(n * sizeof(int));
  if (A == NULL) /* exit program if can't malloc memory */
  {
    printf("Can't Malloc! Please try again.");
    return 1;
  }
  for (i = 0; i < n; i++)
  {
    printf("Enter number[%d]: ", i);
    scanf("%d", &A[i]);
  }

  B = merge_sort_recursive(A, 0, n - 1);
  printf("Sorted Array: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", B[i]);
  }
  printf("\n");

  // free(A);
  // free(B);
  // int m_concat = 4, n_concat = 0;
  // int C[4] = {1, 2, 3, 4};
  // int D[2] = {5, 6};
  // int *F = NULL;
  // int *E = array_concat_i_2(C, 4, F, 0);
  // printf("E: ");
  // for (i = 0; i < m_concat + n_concat; i++)
  // {
  //   printf("%d ", E[i]);
  // }

  // int G[4] = {1, 4};

  // int *H = array_shift_i2(G, 4);
  // for (i = 0; i < 2 - 1; i++)
  // {
  //   printf("%d ", H[i]);
  // }
  // printf("\n");
  return 0;
}