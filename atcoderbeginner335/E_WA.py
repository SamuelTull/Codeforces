import sys
from heapq import heappop , heappush 
input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
adj = {
    i: set() for i in range(N+1)
}
adj[N-1] = {N}
for i in range(M):
    u, v = map(int, input().split())
    u -= 1 
    v -= 1
    if A[u] < A[v]:
        adj[u].add(v)
    elif A[u] > A[v]:
        adj[v].add(u)
    else:
        adj[u] |= adj[v]
        adj[v] = adj[u] 
             
dp = [-1]*(N+1)
Q  = [(1,0)]
dp[0] = 1
while Q:
    d, u = heappop(Q)
            
    for v in adj[u]:
        if dp[v] < dp[u]+1:
            dp[v] = dp[u]+1
            Q.append(v)


print(max(0,dp[-1]-1))