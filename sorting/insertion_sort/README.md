# Insertion sort
Insertion sort works the way you might sort a hand of playing cards
- Start with an empty left hand; all cards are in a pile on the table
- With your right hand, pick up the first card in the pile
- Insert the card into the correct position in your left hand

## Pseudocode
```
INSERTION-SORT(A, n)
1    for i = 1 to n
2        key = A[i]
3        // Insert A[i] into the sorted subarray A[0:i - 1]
4        j = i - 1
5        while j > 0 and A[j] > key
6            A[j + 1] = A[j]
7            j = j - 1
8        A[j + 1] = key
```
Explain by a little example
```
STEP 1:  7  4  5  2     -> No element on left side of 7, so no change in it position
          __
         /  v
STEP 2:  7  4  5  2     -> i = 1, key = A[1] = 4 < A[j = 0] = 7 -> Jump in the while loop to insert
         ^__|              A[j + 1] (A[0 + 1] = 4) to the correct position in the sorted subarray
             __
            /  v
STEP 3:  4  7  5  2
            ^__|
          __ __ __
         /  v  v  v
STEP 4:  4  5  7  2
         ^________|

FINAL:   2  4  5  7
```

## Analysis
The running time of the algorithm is the sum of running times for each statement executed. A statement that takes $c_{\scriptstyle k}$ steps to execute and executes $m$ times contributes $c_{\scriptstyle k}m$ to the total running time.

$c_{\scriptstyle k}$: number of steps to execute statement $k$

$t_{\scriptstyle t}$: the number of times the while loop executed for that value of $i$ ($i = 2,3,...,n$)

The running time of insertion sort on an input of $n$ values:
$$T(n) = c_{\scriptstyle 1}n + c_{\scriptstyle 2}(n - 1) + c_{\scriptstyle 4}(n - 1) + c_{\scriptstyle 5}\sum_{i=1}^{n}t_{\scriptstyle i} + c_{\scriptstyle 6}\sum_{i=1}^{n}(t_{\scriptstyle i} - 1) + c_{\scriptstyle 7}\sum_{i=1}^{n}(t_{\scriptstyle i} - 1) + c_{\scriptstyle 8}(n - 1)$$

The **best case** occurs when the array is already sorted. In this case, each time that line 5 executes, the value of key ($A[i]$ origin value) is already greater than or equal all values in $A[0:i - 1]$, so that the while loop of lines 5-7 always exits upon the first test in line 5. Therefore $t_{\scriptstyle i} = 1$ for $i = 1,2,...,n$

Best-case running time:

$$
\begin{align*}
T(n) &= c_{\scriptstyle 1}n + c_{\scriptstyle 2}(n - 1) + c_{\scriptstyle 4}(n - 1) + c_{\scriptstyle 5}(n - 1) + c_{\scriptstyle 8}(n - 1) \\
&= (c_{\scriptstyle 1} + c_{\scriptstyle 2} + c_{\scriptstyle 4} + c_{\scriptstyle 5} + c_{\scriptstyle 8})n - (c_{\scriptstyle 2} + c_{\scriptstyle 4} + c_{\scriptstyle 5} + c_{\scriptstyle 8})
\end{align*}
$$

The **worst case** arises when the array is in reverse sorted order. The procedure must compare each element $A[i]$ with each element in the entire sorted subarray $A[0:i - 1]$. The procedure find that $A[j] > key$ every time in line 5, and the while loop exits only when $j$ reaches 0 so $t_{\scriptstyle i} = i$ for $i = 2,3,...,n$

$$
\begin{align*}
T(n) &= c_{\scriptstyle 1}n + c_{\scriptstyle 2}(n - 1) + c_{\scriptstyle 4}(n - 1) + c_{\scriptstyle 5}(\frac{n(n + 1)}{2} - 1) + c_{\scriptstyle 6}(\frac{n(n - 1)}{2} - 1) + c_{\scriptstyle 7}(\frac{n(n - 1)}{2} - 1) + c_{\scriptstyle 8}(n - 1)\\
&= (\frac{c_{\scriptstyle 5}}{2} + \frac{c_{\scriptstyle 6}}{2} + \frac{c_{\scriptstyle 7}}{2})n^2 + (c_{\scriptstyle 1} + c_{\scriptstyle 2} + c_{\scriptstyle 4} + \frac{c_{\scriptstyle 5}}{2} - \frac{c_{\scriptstyle 6}}{2} - \frac{c_{\scriptstyle 7}}{2} + c_{\scriptstyle 8})n
\end{align*}
$$

The running is a **quadratic function** of $n$

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