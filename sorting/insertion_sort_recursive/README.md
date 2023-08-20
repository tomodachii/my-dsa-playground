# Insertion sort recursive
This is the recursive version for Insertion sort algorithm
## Pseudocode
```
INSERTION-SORT-RECURSIVE(A, n)
1    if n <= 0 return // base case
2    INSERTION-SORT-RECURSIVE(A, n - 1) // Making recursive call to reach the base case
3    key = A[n - 1]
4    j = n - 2
5    while j > 0 and A[j] > key
6        A[j + 1] = A[j]
7        j = j - 1
8    A[j + 1] = key
```
The running time of the algorithm is the sum of running times for each statement executed. A statement that takes $c_{\scriptstyle k}$ steps to execute and executes $m$ times contributes $c_{\scriptstyle k}m$ to the total running time.

The running time of recursive insertion sort on an input of $n$ values:
$$T(n) = c_{\scriptstyle 1}n + c_{\scriptstyle 2}(n - 1) + c_{\scriptstyle 3}(n - 1) + c_{\scriptstyle 4}(n - 1) + c_{\scriptstyle 5}\sum_{i=2}^{n}t_{\scriptstyle i} + c_{\scriptstyle 6}\sum_{i=2}^{n}(t_{\scriptstyle i} - 1) + c_{\scriptstyle 7}\sum_{i=2}^{n}(t_{\scriptstyle i} - 1) + c_{\scriptstyle 8}(n - 1)$$

The running time is equal to normal insertion sort
## Test Drive
The test is designed to implement 3 cases:
- Average Case: All items in the array are randomly ordered
- Best Case: The array is already sorted
- Worst Case: The array is reverse sorted

To run the test you can use the Makefile
```
make test
```

To clean up the mess you made:
```
make clean
```