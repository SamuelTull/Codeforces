import os
from io import BytesIO
from math import ceil

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


for _ in range(int(input())):
    w, f = map(int, input().split())
    m, M = min(w, f), max(w, f)
    n = int(input())
    s = list(map(int, input().split()))
    sum_s = sum(s)
    dp = [False] * (sum_s + 1)
    dp[0] = True
    for i in range(n):
        for j in range(sum_s, s[i] - 1, -1):
            dp[j] |= dp[j - s[i]]
    # precompute max up to i for all i
    # rather than for each t going back to the previous max
    for i in range(sum_s + 1):
        if dp[i]:
            dp[i] = i
        else:
            dp[i] = dp[i - 1]
    t = 0
    while True:
        if sum_s - dp[min(sum_s, M * t)] <= m * t:
            ans.append(t)
            break
        t += 1

os.write(1, "\n".join(map(str, ans)).encode())
