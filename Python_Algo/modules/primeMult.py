#-*-coding:utf-8-*-
from heapq import *

n = int(input())
primes = list(map(int, input().split()))

s = 2
while True:
    t = s
    for p in primes:
        while t%p == 0: # �Ҽ��� �ƴ�
            t //= p # t = 1�� ������ ������
    if t==1:
        n -= 1
        if n == 0:
            break
    s+=1

print(s)

heap = primes[:]
heapify(heap)

for _ in range(n):
    s = heappop(heap)
    for p in primes:
        heappush(heap, p*s)

print(heappop(heap))


