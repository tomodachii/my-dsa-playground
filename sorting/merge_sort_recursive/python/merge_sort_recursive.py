def merge(a, b):
    if len(a) == 0:
        return b
    elif len(b) == 0:
        return a
    elif a[0] < b[0]:
        return [a[0]] + merge(a[1:], b)
    else:
        return [b[0]] + merge(a, b[1:])
    
def mergesort(x):
    if len(x) < 2:
        return x
    else:
        h = len(x) // 2
        return merge(mergesort(x[:h]), mergesort(x[h:]))