#-*-coding:utf-8-*-
# Get the number of islands
from queue import Queue

# dfs
# M     [IN] map
# r     [IN] start row
# c     [In] start column
def dfs(M, r, c):
    M[r][c] = 0 # ¹æ¹®
    dxy = ( (0, 1), (1, 0), (0, -1), (-1, 0))
    for (dr, dc) in dxy:
        nr = r + dr
        nc = c + dc
        # boundary check
        if nr < 0 or nr >= len(M):
            continue
        if nc < 0 or nc >= len(M[0]):
            continue
        # check whether we can go there
        if M[nr][nc] == 0:
            continue
        # recursive call
        dfs(M, nr, nc)

# bfs
def bfs(M, r, c):
    # make a queue
    q = Queue()
    q.put((r, c))
    # Run while queue is not empty
    while not q.empty():
        (r, c) = q.get()
        if M[r][c] == 0:
            continue
        M[r][c] = 0
        dxy = ( (0, 1), (1, 0), (0, -1), (-1, 0))
        for (dr, dc) in dxy:
            nr = r + dr
            nc = c + dc
            # boundary check
            if nr < 0 or nr >= len(M):
                continue
            if nc < 0 or nc >= len(M[0]):
                continue
            # check whether we can go there
            if M[nr][nc] == 0:
                continue
            q.put((nr, nc))

n, m = map(int, input().split())
M = [ [0]*m for _ in range(n)] # make a multi-list sized nxm

for i in range(n):
    s = input()
    for j in range(m):
        if s[j] == "1":
            M[i][j] = 1
        else: 
            M[i][j] = 0
    
islands = 0
for i in range(n):
    for j in range(n):
        if M[i][j] == 0:
            continue
        islands += 1
        bfs(M, i, j)

print(islands)