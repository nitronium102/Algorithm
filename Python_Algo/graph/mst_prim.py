#-*-coding:utf-8-*-
# MST(Prim version)
from queue import PriorityQueue

Infinity = 1000000000

v, e = map(int, input().split())
# adjacent lisf
adj = [ [] for _ in range(v)]
for _ in range(e):
    a, b, w = map(int, input().split())
    # direct adjacent list
    adj[a-1].append((b-1, w))
    adj[b-1].append((a-1, w))

# Make a priority queue
pq = PriorityQueue()

# vertex value
d = [ Infinity ]*v

# visited or not
visit = [ False ]*v # not visited

# start vertex
d[0] = 0
pq.put((0, 0)) # first value : vertex value, second value : vertex index

# queue is not empty
MST = 0
while not pq.empty():
    # get smallest priority from queue
    (_, u) = pq.get()
    if visit[u]:
        continue
    visit[u] = True
    MST += d[u]
    for (to, w) in adj[u]:
        if not visit[to] and d[to] > w:
            d[to] = w
            pq.put((d[to], to))

print(MST)

