#-*-coding:utf-8-*-
from itertools import permutations

n = int(input("n = "))

queens = [ i for i in range(n) ]

count = 0
for p in permutations(queens):
	d1 = set()
	d2 = set()
	isValid = True
	for i in range(n):
		if p[i]+i in d1:
			isValid = False
			break
		if p[i]-i in d2:
			isValid = False
			break
		d1.add(p[i]+i)
		d2.add(p[i]-i)
	if isValid: count += 1
	
print(count)

def backtrack(c, n, qs, d1, d2):
	# success
	if c == n: return 1
	count = 0
	for i in range(n):
		if i in qs: continue
		if i+c in d1: continue
		if i-c in d2: continue
		qs.add(i)
		d1.add(i+c)
		d2.add(i-c)
		count += backtrack(c+1, n, qs, d1, d2)
		qs.remove(i)
		d1.remove(i+c)
		d2.remove(i-c)
	return count

print(backtrack(0, n, set(), set(), set()))
