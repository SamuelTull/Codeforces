import sys
from heapq import heappop, heappush
input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
adj = {
    i: set() for i in range(N)
}

rep_for = {i:{i} for i in range(N)}

for i in range(M):
    u, v = map(int, input().split())
    u -= 1 
    v -= 1

    if A[u] < A[v]:
        adj[u].add((v,1))
    elif A[u] > A[v]:
        adj[v].add((u,1))
    else:
        rep_for[u] |= rep_for[v]
        rep_for[v] = rep_for[u] 
        adj[u] |= adj[v]
        adj[v] = adj[u]

rep = {}
for i in range(N-1 , -1 ,-1 ): # backwards to do N-1 first 
    if i in rep:
        continue 
    for j in rep_for[i]:
        rep[j] = i 



Q = [(1,rep[0])]
seen = [-1] * N 
seen[rep[0]] = 1 
while Q:
    d,u = heappop(Q)
    for (v,dd) in adj[u]:
        v = rep[v]
        if seen[v] < d + dd:
            heappush(Q, (d+dd,v))
            seen[v] = d+dd 

print(max(0, seen[-1] ) )
