#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"

int main(void) {
    int *A, n, i;
    printf("Enter Array size: ");
    scanf("%d", &n);
    if (n <= 0) /* exit program if arraysize is not greater than 0 */
    {
        printf("Array size must be Greater than 0!\n");
        return 1;
    }
    A = (int *)malloc(n * sizeof(int));
    if (A == NULL) /* exit program if can't malloc memory */
    {
        printf("Can't Malloc! Please try again.");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Enter number[%d]: ", i);
        scanf("%d", &A[i]);
    }

    merge_sort(A, 0, n - 1);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);

    return 0;
}