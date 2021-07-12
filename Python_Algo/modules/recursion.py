#-*-coding:utf-8-*-
# c : 현재 만들어진 리스트의 수
# k : 선택되는 전체 수
# v : 소스
# s : 현재까지의 결과
def perm(c, k, v, s):
    if c==k:
        print(s)
        return
    for t in v:
        if t in s:
            continue
        perm(c+1, k, v, s+(t, ))

v = input("list = ").split()
k = int(input("k = "))
perm(0, k, v, tuple())