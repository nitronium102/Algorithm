#-*-coding:utf-8-*-
import time
import random
import heapq

def partition(v, a, b):
    # pivot = last value
    # i = first value
    # j = value bigger than pivot
    pivot, i, j = v[b], a, b-1
    while i<=j:
        if v[i] <= pivot:
            i+=1
        else:
            v[i], v[j] = v[j], v[i]
            j -= 1
    v[i], v[b] = pivot, v[i]
    return i


def quickSort(v, a, b):
    if a>=b: return # no data
    c = partition(v, a, b)
    quickSort(v, a, c-1)
    quickSort(v, c+1, b)

random.seed(100)
n = int(input("n ="))
v = [ random.randrange(1000000) for _ in range(n) ]

ts = time.time()
quickSort(v, 0, n-1)
#heapq.heapify(v)
#v = [ heapq.heappop(v) for _ in range(len(v))]
et = int((time.time() - ts)*1000)
print(*v[:10])
print(f"Elapsed time is {et}ms.")
