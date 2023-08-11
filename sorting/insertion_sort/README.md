# Insertion sort
Insertion sort works the way you might sort a hand of playing cards
 - Start with an empty left hand; all cards are in a pile on the table
 - With your right hand, pick up the first card in the pile
 - Insert the card into the correct position in your left hand

## Pseudocode
```
INSERTION-SORT(A, n)
    for i = 1 to n
        key = A[i]
        // Insert A[i] into the sorted subarray A[0:i - 1]
        j = i - 1
        while j > 0 and A[j] > key
            A[j + 1] = A[j]
            j = j - 1
        A[j + 1] = key
```
Explain by an example
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

## Test
```
make test
```