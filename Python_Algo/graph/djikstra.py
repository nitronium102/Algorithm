#-*-coding:utf-8-*-
# MST(Prim version)
from queue import PriorityQueue

Infinity = 1000000000

v, e, s = map(int, input().split())
# adjacent lisf
adj = [ [] for _ in range(v)]
for _ in range(e):
    a, b, w = map(int, input().split())
    # direct adjacent list
    adj[a-1].append((b-1, w))

# Make a priority queue
pq = PriorityQueue()

# vertex value
d = [ Infinity ]*v

# visited or not
visit = [ False ]*v # not visited

# start vertex
d[s-1] = 0 # s-1 : index
pq.put((0, s-1)) # first value : vertex value, second value : vertex index

# queue is not empty
while not pq.empty():
    # get smallest priority from queue
    (_, u) = pq.get()
    if visit[u]:
        continue
    visit[u] = True
    for (to, w) in adj[u]:
        if not visit[to] and d[to] > d[u] + w:
            d[to] = d[u] + w # dijkstra : start + weight
            pq.put((d[to], to))

for t in d:
    print(t if t != Infinity else "INF")


