#-*-coding:utf-8-*-
n = int(input())
ofs = list(map(int, input().split()))

# left : fail, right : pass
left, right = 0, ofs[0]*n
while left+1 < right: # 서로 이웃하지 않을 때
    mid = (left+right)//2
    prs = 0 # 심사받는 사람
    for o in ofs:
        prs += mid//o
    if prs >= n: # 사람들이 모두 pass
        right = mid
    else:
        left = mid

print(right)