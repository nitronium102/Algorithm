#-*-coding:utf-8-*-
from bisect import bisect_left

L, K, C = map(int, input().split())
cuts = list(map(int, input().split()))
# add [0, L] into cust list for convinient search
cuts = [0, L]

def isPass(cuts, longest, c):
    cur = cuts[-1] # current position
    while c>0: # can cut
        f = cur - longest
        if f <= 0:
            return True, cuts[1] # firstcut = cuts[1]
        idx = bisect_left(cuts, f)
        if cur == idx: # cannot cut
            return False, 0
        c -= 1
    if cur > longest:
        return False, 0
    return True, cur

# binary search
left, right = 0, L
firstCut = L
while left + 1 < right:
    mid = (left+right)//2
    r, fc = isPass(cuts, mid, C)
    if r:
        right = mid
        firstCut = fc
    else :
        left = mid

print(right, firstCut)


