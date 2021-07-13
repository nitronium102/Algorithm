#-*-coding:utf-8-*-
from itertools import combinations

L, K, C = map(int, input().split())
cuts = list(map(int, input().split()))
cuts.sort()

glongest = L
gfirst = L
for c in combinations(cuts, C):
	longest = c[0]
	first = c[0]
	for i in range(C-1):
		if c[i+1]-c[i] > longest: longest = c[i+1]-c[i]
	if L-c[-1] > longest: longest = L-c[-1]
	if glongest > longest:
		glongest = longest
		gfirst = first
	elif glongest == longest and gfirst > first:
		gfirst = first

print(glongest, gfirst)
