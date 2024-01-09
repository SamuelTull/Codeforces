import sys
from collections import deque 
input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
adj = {
    i: set() for i in range(N)
}
for i in range(M):
    u, v = map(int, input().split())
    u -= 1 
    v -= 1

    if A[u] < A[v]:
        adj[u].add((v,1))
    elif A[u] > A[v]:
        adj[v].add((u,1))
    else:
        adj[u].add((v,0))
        adj[v].add((u,0))


Q = deque([(1,0)])
seen = [-1] * N 
while Q:
    d,u = Q.popleft()
    for (v,dd) in adj[u]:
        if seen[v] < d + dd:
            Q.append((d+dd,v))
            seen[v] = d+dd 

print(max(0, seen[-1]))
