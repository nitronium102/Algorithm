# 정렬했을 때 특정 idx의 값을 가져오고 싶은 경우
import time
import random
import heapq

def partition(v, a, b):
	pivot, i, j = v[b], a, b-1
	while i <= j:
		if v[i] <= pivot: i += 1
		else:
			v[i], v[j] = v[j], v[i]
			j -= 1
	v[i], v[b] = pivot, v[i]
	return i

def nthElement(v, a, b, k):
	if a >= b: return v[a]
	c = partition(v, a, b)
	if c == k: return v[c]
	if c > k: return nthElement(v, a, c-1, k)
	return nthElement(v, c+1, b, k)

random.seed(100)
n, k = map(int, input("n, k = ").split())
v = [ random.randrange(100000000) for _ in range(n) ]

ts = time.time()
#r = nthElement(v, 0, n-1, k)
v.sort()
r = v[k]
et = int((time.time() - ts)*1000)
print(r)
print(f"Elapsed time is {et}ms.")
