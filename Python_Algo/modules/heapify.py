#-*-coding:utf-8-*-
import heapq

h = list(map(int.input("���� �Է�: ").split()))
heapq.heapify(h)
print([heapq.heappop(h) for _ in range(len(h))])