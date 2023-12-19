import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

M = 998244353

for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    nxt = [0] * n
    nxt[n - 1] = n
    for i in range(n - 2, -1, -1):
        nxt[i] = i + 1
        while nxt[i] < n and nums[i] < nums[nxt[i]]:
            nxt[i] = nxt[nxt[i]]
    dp = [0] * (n + 1)
    dp_sub = [0] * (n + 1)
    dp_nxt = [0] * (n + 1)
    dp_nxt[0] = 1
    a = 0
    for i in range(n):
        dp[i] = (dp_nxt[i] + dp_sub[i]) % M
        dp_sub[i + 1] = (dp_sub[i + 1] + dp[i]) % M
        dp_sub[nxt[i]] = (dp_sub[nxt[i]] - dp[i]) % M
        dp_nxt[nxt[i]] = (dp_nxt[nxt[i]] + dp[i]) % M
        dp_sub[i + 1] = (dp_sub[i + 1] + dp_sub[i]) % M
        dp_nxt[nxt[i]] = (dp_nxt[nxt[i]] + dp_nxt[i]) % M
        if nxt[i] == n:
            a = (a + dp[i]) % M
    ans.append(str(a))

os.write(1, "\n".join(ans).encode())


# n, reachable
# 1 1
# 2 2
# 3 123 -> 1+2+1, 132 -> 1+1+1

# 1234 -> 134 124 123 -> 12 13 14 -> 1
# 1342 -> 132 142 -> 12 -> 1


# 01234 -> 0234 0134 0124 0123 -> 034 024 023 014 013 012 -> 01 02 03 04 -> 0
# 02341 -> 0
