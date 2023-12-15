import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
import sys

sys.setrecursionlimit(10**6)  # Increase the recursion limit


def dfs(u):  # DP[u]=max for tree rooted at u
    DP[u] = nums[u]
    for v in adj[u]:
        if v != parent[u]:
            parent[v] = u
            dfs(v)
            DP[u] += max(0, DP[v])


def dfs2(u):  # ans[u]=max for tree including u (not neccesarily rooted at)
    DP[u] = DP[u] + max(0, DP[parent[u]] - max(0, DP[u]))
    for v in adj[u]:
        if v != parent[u]:
            dfs2(v)


n = int(input())
nums = [1 if int(x) == 1 else -1 for x in input().split()]
adj = [[] for _ in range(n)]
parent = [-1 for _ in range(n)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    adj[u - 1].append(v - 1)
    adj[v - 1].append(u - 1)
DP = [0 for _ in range(n)]
dfs(0)
for u in adj[0]:
    dfs2(u)
os.write(1, "\n".join(map(str, DP)).encode())
