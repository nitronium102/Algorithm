from itertools import combinations

v = list(map(int, input().split()))
k = v[0]
B = v[1:]

for v in combinations(B, 5):
    print(*v)
    #print(" ".join(list(map(str(, v)))) # v ���� �����ϵ� �߰��� ���� �ֱ�

'''
for s in combinations(v[1:], 5):
    print(" ".join(s))
'''