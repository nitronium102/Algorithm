#-*-coding:utf-8-*-
# c : ���� ������� ����Ʈ�� ��
# k : ���õǴ� ��ü ��
# v : �ҽ�
# s : ��������� ���
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