#-*-coding:utf-8-*-
import time
import random

def selectionSort(v):
	n = len(v)
	for i in range(n-1):
		m = i
		for j in range(i+1, n):
			if v[m] > v[j]: m = j
		v[m], v[i] = v[i], v[m]

def insertionSort(v):
    n = len(v)
    for i in range(1, n):
        t, last = v[i], i-1
        while last >=0 and v[last]>t:
            v[last+1] = v[last]
            last -= 1
        v[last+1] = t

random.seed(100)
n = int(input("n = "))
#v = [ random.randrange(1000000) for _ in range(n) ]
v = [ random.randrange(1000)+ _ for _ in range(n) ]

ts = time.time()
insertionSort(v)
#selectionSort(v)
et = int((time.time() - ts)*1000)
print(*v[:10])
print(f"Elapsed time is {et}ms.")
