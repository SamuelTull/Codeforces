import os
from io import BytesIO
from collections import deque

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline


# def dfs(u, p):  # DP[u]=max for tree rooted at u
#     DP[u] = nums[u]
#     for v in adj[u]:
#         if v != p:
#             dfs(v, u)
#             DP[u] += max(0, DP[v])


# def dfs2(u, p):  # ans[u]=max for tree including u (not neccesarily rooted at)
#     ans[u] += max(0, ans[p] - max(0, DP[u]))
#     for v in adj[u]:
#         if v != p:
#             dfs2(v, u)


n = int(input())
nums = [1 if int(x) == 1 else -1 for x in input().split()]
adj = [[] for _ in range(n)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    adj[u - 1].append(v - 1)
    adj[v - 1].append(u - 1)
DP = [-2 for _ in range(n)]  # cant be below -1

Q = deque([(0, -1)])
while Q:
    (u, p) = Q.popleft()
    ok = True
    s = nums[u]
    for v in adj[u]:
        if v != p:
            if DP[v] == -2:
                Q.append((v, u))
                ok = False
            else:
                s += max(0, DP[v])
    if ok:
        DP[u] = s
    else:
        Q.append((u, p))

Q = deque([(u, 0) for u in adj[0]])
while Q:
    (u, p) = Q.popleft()
    DP[u] = DP[u] + max(0, DP[p] - max(0, DP[u]))
    for v in adj[u]:
        if v != p:
            Q.append((v, u))

os.write(1, "\n".join(map(str, DP)).encode())
