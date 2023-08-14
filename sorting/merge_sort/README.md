# Merge sort
Sort a subarray $A[p:r]$, starting with the entire array $A[0:n], recursing down to smaller and smaller subarrays (starting array $A[0:n]$ will be divided to a point when it becomes $A[p:r]$)
 - **Divide** $A[p:r]$ into $A[p:q]$ and $A[q+1:r]$ with $q$ is the midpoint of $A[p:r]$
 - **Conquer** by sorting $A[p:q]$ and $A[q+1:r]$ recursively using merge sort
 - **Combine** (Merge) by merging 2 sorted subarray $A[p:q]$ and $A[q+1:r]$ back into $A[p:r]$

## Psuedo Code and Analysis
I really love the ```MERGE procedure``` explanation in the book

Basically, you have two piles of cards *face up* on a table. Each pile is sorted, with the smallest-value cards on top. You wish to merge the two piles into a single sorted output pile, which is to be *face down* on the table.
- Choosing the smaller of the two cards on top of the *face-up* piles
- Removing it from its pile - which exposes a new top card 
- Placing this card *face down* onto the output pile

Repeat this step until one input pile is empty, at which time you can just take the remaining input pile and flip over the entire pile, placing it face down onto the output pile

```
MERGE(A, p, q, r)
1   n_l = q - p + 1 // length of A[p:q]
2   n_r = r - q // length of A[q + 1:r]
3   let L[0:n_l - 1] and R[0:n_r - 1] be new arrays
4   for i = 0 to n_l - 1
5       L[i] = A[p + i]
6   for j = 0 to n_r - 1
7       R[j] = A[q + j + 1]
8   i = 0   // i indexes the smallest remaining element in L
9   j = 0   // j indexes the smallest remaining element in R
10  k = p   // k indexes the location of A to fill
11  // As long as each of the arrays L and R contains an unmerged element,
    // copy the smallest unmerged element back into A[p:r].
12  while i < n_l an j < n_r
13      if L[i] <= R[j]
14          A[k] = L[i]
15          i = i + 1
16      else A[k] = R[j]
17          j = j + 1
18      k = k + 1
19  // Having gone through one of L and R entirely, since both L and R are sorted, 
    // the remainder of the other array will only contains sorted items in the right 
    // order! copy the remainder of the other to the end of A[p:r]
20  while i < n_l
21      A[k] = L[i]
22      i = i + 1
23      k = k + 1
24  while j < n_r
25      A[k] = L[j]
26      j = j + 1
27      k = k + 1
```

MERGE procedure runs in $\theta(n)$ time, where $n = r - p + 1$:
 - Lines 1-3 and 8-10 takes constant time
 - The for loops of lines 4-7 take $\theta(n_{\scriptstyle L} + n_{\scriptstyle R}) = \theta(n)$ time
 - All 3 while loops of lines 12-27 will eventually copies all items from L and R back into A and every value is copied exactly once. Therefore, total time spent in these loops is $\theta(n)$

The procedure MERGE-SORT(A, p, r) sorts the elements in the subarray $A[p:r]$
 - If $p = r$, the subarray has just 1 element and therefore is sorted
 - Otherwise, $p < r$, MERGE-SORT runs the divide, conquer and combine steps.
 ```
MERGE-SORT(A, p, r)
1   if p >= r // zero or one element?
2       return
3   q = [(p + r)/2] // midpoint of A[p:r]
4   MERGE-SORT(A, p, q) // recursively sort A[p:q]
5   MERGE-SORT(A, q + 1, r) // recursively sort A[q + 1:r]
6   // Merge A[p:q] and A[q + 1:r] into A[p:r]
7   MERGE(A, p, q, r)
```

### Analysis of Divide-and-conquer
let $T(n)$ be the worst-case running time on a problem of size $n$. If the problem size is small enough, say $n < n_{\scriptstyle 0}$ ($n_{\scriptstyle 0} > 0$), the *straightforward solution* take contsant time $\theta(1)$ 
> This does not imply that the running time is literally 1 unit, it means the something rather than divide-and-conquer, for example, with small unsorted array, insertion sort might be better (straightforward solution) and will take constant $c$ time which is $\theta(1)$

Suppose that the division of the problem yields $a$ subproblems, each with size $n/b$, that is, $1/b$ the size of the original.
- $D(n)$ time to to divide the problem into subproblem
- $T(n/b)$ solve one subproblem of size $n/b$
- $aT(n/b)$ time to solve all $a$ subproblems
- $C(n)$ time to combine the solution to subproblems into the solution of the original problem

$$
T(n) = 
\begin{cases}
    \theta(1) &\text{if}\, n < n_{\scriptstyle 0},\\
    D(n) + aT(n/b) + C(n) &\text{otherwise}.
\end{cases}
$$

### Analysis of Merge sort
- **Divide:** The divide step just computes the middle of the subarray, which takes constant time. Thus, $D(n) = \theta(1)$
- **Conquer:** Since both $a$ (subproblems) and $b$ ($1/b$ is the size of the subproblem) are 2, recursively solving two subproblems, each of size $n/2$, contributes $2T(n/2)$ to the running time
- **Combine:** Since the MERGE procedure on an $n$-element subarray and for merge sort, takes $\theta(n)$ time, we have $C(n) = \theta(n)$

As big O notation focuses on the growth rate of the function as the input size becomes large, we can ignore $\theta(1)$
$$
\begin{align*}
T(n) = 2T(n/2) + \theta(n)
\end{align*}
$$

$T(n) = \theta(n\log_2 n)$. To understand in intuitively why, for simplicity, assume that n is an exact power of 2 and that the implicit base case is $n = 1$
$$
T(n) = 
\begin{cases}
    c{\scriptstyle 1} &\text{if}\, n = 1,\\
    2T(n/2) + c_{\scriptstyle 2}n &\text{if}\, n > 1.
\end{cases}
$$

- $c{\scriptstyle 1} > 0$ represents the time required to solve a problem of size 1 (case $p = r$)
- $c{\scriptstyle 2} > 0$ is the time per array element of the divide and combine steps (case $p < r$)

```
  ^
  |    T(n)             c2n  ------------------------> c2n
  |                    /   \
  |                   /     \
  |                  /       \
  |                 /         \
  |                /           \
  |             c2n/2           c2n/2  --------------> c2n
  |            /     \         /     \
lgn + 1        |     |         |     |
  |         c2n/4   c2n/4   c2n/4   c2n/4  ----------> c2n
  |         /   \   /   \   /   \   /   \               
  |         |   |   |   |   |   |   |   |               
  |         |   |   |   |   |   |   |   |               .
  |                                                     .
  |         .   .   .   .   .   .   .   .               .
  |         .   .   .   .   .   .   .   .               
  |         .   .   .   .   .   .   .   .
  |         c1  c1  c1  c1  c1  c1..c1  c1  ---------> c1n
  |        \--------------v---------------/
  |                       n
  v
```
Since we're assuming that n is an exact power of 2, the number of levels of a recursion tree with $2^i$ leaves is $log_2 2^i + 1$

The levels above the leaves each cost $c_{\scriptstyle 2}n$, and the leaf level costs $c_{\scriptstyle 1}n$, for a total cost of $c_{\scriptstyle 2}n\log_2 n + c_{\scriptstyle 1}n = \theta(n\log_2 n)$