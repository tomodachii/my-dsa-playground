# Merge sort
Sort a subarray $A[p:r]$, starting with the entire array $A[0:n], recursing down to smaller and smaller subarrays (starting array $A[0:n]$ will be divided to a point when it becomes $A[p:r]$)
 - **Divide** $A[p:r]$ into $A[p:q]$ and $A[q+1:r]$ with $q$ is the midpoint of $A[p:r]$
 - **Conquer** by sorting $A[p:q]$ and $A[q+1:r]$ recursively using merge sort
 - **Combine** (Merge) by merging 2 sorted subarray $A[p:q]$ and $A[q+1:r]$ back into $A[p:r]$

## Analysis

I really love the ```MERGE procedure``` explanation in the book

Basically, you have two piles of cards *face up* on a table. Each pile is sorted, with the smallest-value cards on top. You wish to merge the two piles into a single sorted output pile, which is to be *face down* on the table.
- Choosing the smaller of the two cards on top of the *face-up* piles
- Removing it from its pile - which exposes a new top card 
- Placing this card *face down* onto the output pile

Repeat this step until one input pile is empty, at which time you can just take the remaining input pile and flip over the entire pile, placing it face down onto the output pile