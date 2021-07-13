#-*-coding:utf-8-*-
n = int(input())
ofs = list(map(int, input().split()))

# left : fail, right : pass
left, right = 0, ofs[0]*n
while left+1 < right: # ���� �̿����� ���� ��
    mid = (left+right)//2
    prs = 0 # �ɻ�޴� ���
    for o in ofs:
        prs += mid//o
    if prs >= n: # ������� ��� pass
        right = mid
    else:
        left = mid

print(right)