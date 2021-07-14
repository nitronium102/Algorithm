#-*-coding:utf-8-*-
import time
import random

def merge(v, a, c, b):
    temp = []
    i, j = a, c+1
    while i<= c and j<=b: # ū �ֵ鸸 ����
        if v[i] < v[j]: 
            temp.append(v[i])
            i+=1
        else:
            temp.append(v[j])
            j+=1
    
    # ���� �ֵ� ����
    while i<=c:
        temp.append(v[i])
        i += 1
    while j<=b:
        temp.append(v[j])
        j+=1
        
    # temp�� �ִ� �ֵ� ��������
    for i in range(len(temp)):
        v[a+i]=temp[i]

def mergeSort(v, a, b):
    if a==b: return
    c = (a+b)//2
    mergeSort(v, a, c)
    mergeSort(v, c+1, b)
    merge(v, a, c, b)

n = int(input("n = "))
v = [random.randrange(100000000) for _ in range(n)]

ts = time.time()
mergeSort(v, 0, n-1)
et = int((time.time()-ts)*1000)
print(*v[:10])
print(f"Elapsed time is {et}ms.")
