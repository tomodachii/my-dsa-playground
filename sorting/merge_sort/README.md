# Merge sort
Sort a subarray $A[p:r]$, starting with the entire array $A[0:n-1]$, recursing down to smaller and smaller subarrays (the starting array $A[0:n-1]$ will be divided to a point when it becomes $A[p:r]$)
 - **Divide** $A[p:r]$ into $A[p:q]$ and $A[q+1:r]$ with $q$ is the midpoint of $A[p:r]$
 - **Conquer** by sorting $A[p:q]$ and $A[q+1:r]$ recursively using merge sort
 - **Combine** (Merge) by merging 2 sorted subarray $A[p:q]$ and $A[q + 1:r]$ back into $A[p:r]$

## MERGE-SORT procedure
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

## Psuedo Code and Analysis for the MERGE procedure
I really love the ```MERGE procedure``` explanation in the book

Basically, you have two piles of cards *face up* on a table. Each pile is sorted, with the smallest-value cards on top. You wish to merge the two piles into a single sorted output pile, which is to be *face down* on the table (so the newly created pile will later be *face up* with smallest-value cards on top).

PART 1:
- Choosing the smaller of the two cards on top of the *face-up* piles
- Removing it from its pile - which exposes a new top card 
- Placing this card *face down* onto the output pile
PART 2:
- Repeat this step until one input pile is empty, at which time you can just take the remaining input pile and flip over the entire pile, placing it face down onto the output pile

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
    // PART 1 of the MERGE procedure -> choose the smaller one from both piles until
    // one pile is empty!
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
    // PART 2 of the MERGE procedure -> take all cards of remaining input pile!
20  while i < n_l
21      A[k] = L[i]
22      i = i + 1
23      k = k + 1
24  while j < n_r
25      A[k] = L[j]
26      j = j + 1
27      k = k + 1
```

MERGE procedure runs in $\Theta(n)$ time, where $n = r - p + 1$:
 - Lines 1-3 and 8-10 takes constant time
 - The for loops of lines 4-7 take $\Theta(n_{\scriptstyle L} + n_{\scriptstyle R}) = \Theta(n)$ time
 - All 3 while loops of lines 12-27 will eventually copies all items from L and R back into A and every value is copied exactly once. Therefore, total time spent in these loops is $\Theta(n)$


### Analysis of Divide-and-conquer
let $T(n)$ be the worst-case running time on a problem of size $n$. If the problem size is small enough, say $n < n_{\scriptstyle 0}$ ($n_{\scriptstyle 0} > 0$), the *straightforward solution* take contsant time $\Theta(1)$ 
> This does not imply that the running time is literally 1 unit, it means the something rather than divide-and-conquer, for example, with small unsorted array, insertion sort might be better (straightforward solution) and will take constant $c$ time which is $\Theta(1)$

Suppose that the division of the problem yields $a$ subproblems, each with size $n/b$, that is, $1/b$ the size of the original.
- $D(n)$ time to to divide the problem into subproblem
- $T(n/b)$ solve one subproblem of size $n/b$
- $aT(n/b)$ time to solve all $a$ subproblems
- $C(n)$ time to combine the solution to subproblems into the solution of the original problem

$$
T(n) = 
\begin{cases}
    \Theta(1) &\text{if}\, n < n_{\scriptstyle 0},\\
    D(n) + aT(n/b) + C(n) &\text{otherwise}.
\end{cases}
$$

### Analysis of Merge sort
- **Divide:** The divide step just computes the middle of the subarray, which takes constant time. Thus, $D(n) = \Theta(1)$
- **Conquer:** Since both $a$ (subproblems) and $b$ ($1/b$ is the size of the subproblem) are 2, recursively solving two subproblems, each of size $n/2$, contributes $2T(n/2)$ to the running time
- **Combine:** Since the MERGE procedure on an $n$-element subarray and for merge sort, takes $\Theta(n)$ time, we have $C(n) = \Theta(n)$

As big O notation focuses on the growth rate of the function as the input size becomes large, we can ignore $\Theta(1)$
$$
\begin{align*}
T(n) = 2T(n/2) + \Theta(n)
\end{align*}
$$

$T(n) = \Theta(n\log_2 n)$. To understand in intuitively why, for simplicity, assume that n is an exact power of 2 and that the implicit base case is $n = 1$
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
Consider a recursion tree with i levels

There is $2^0$ leaf (1 leaf) at level 1.

There are $2^1$ leaves (2 leaves) at level 2.

There are $2^2$ leaves (4 leaves) at level 3.

There are $2^3$ leaves (8 leaves) at level 4.

...

There are $2^{i-1}$ leaves at level i.

At each level of recursion, the problem size (number of elements) is halved. Therefore, after i levels of recursion, the problem size becomes $n/(2^{i-1})$.

We want to find out how many levels of recursion are needed until the problem size reduces to 0 (i.e., we reach the base case). So, we solve for k in the equation $n/(2^{i-1}) = 0$.

$$
\begin{aligned}
n = 2^{i-1} &\iff log_2{n} = log_2{2^{i-1}} \\
&\iff log_2{n} = i - 1 \\
&\iff i = log_2{n} + 1
\end{aligned}
$$

Since we're assuming that n is an exact power of 2, the number of levels __i__ is $log_2{n} + 1=log_2{2^{i-1}} + 1$.

The levels above the leaves each cost $c_{\scriptstyle 2}n$, and the leaf level costs $c_{\scriptstyle 1}n$, for a total cost of $c_{\scriptstyle 2}n\log_2 n + c_{\scriptstyle 1}n = \Theta(n\log_2 n)$
> As the input size n becomes large, the logarithmic term will dominate the linear term ($c_{\scriptstyle 1}n$). Hence $c_{\scriptstyle 2}n\log_2 n + c_{\scriptstyle 1}n = \Theta(n\log_2 n)$

The merging step always takes $\Theta(n)$ time, no matter the specific elements being merged, because it involves comparing and copying each element exactly once from the two subarrays to the merged result. This is why the worst-case time complexity for merge sort is determined by the number of merge operations, which is proportional to the depth of the recursion tree (which is $\log_2 n$). Therefore the worst-case time complexity is $\Theta(n\log_2 n)$

## Test Drive
Since this algorithm run time complexity depends on the depth of the recursion tree (input quantity), the test drive will be simple (taken from the famous github Algorithm/C repo)

You can give merge_sort a test drive using Makefile
```
make test
```

To clean up the mess:
```
make clean
```