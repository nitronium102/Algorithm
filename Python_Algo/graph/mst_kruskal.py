#-*-coding:utf-8-*-
# MST(Kruskal version)

# S : union
# k : key value
def getRoot(S, k):
    if ( k == S[k]): # root
        return k
    S[k] = getRoot(S, S[k])
    return S[k]

v, e = map(int, input().split())

# edge list
E = []

for _ in range(e):
    a, b, w = map(int, input().split())
    E.append((w, a-1, b-1)) # w is first for sorting
E.sort()

# Make v sets for set operation
S = [ i for i in range(v)] 
MST = 0
for (w, a, b) in E:
    # get roots of a and b from sets
    ra = getRoot(S, a)
    rb = getRoot(S, b)
    # if set a and set b are same set
    if ra == rb: continue
    # union a and b
    S[rb] = ra
    MST += w

print(MST)