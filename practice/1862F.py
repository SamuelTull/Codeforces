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
    # dp = [False] * (sum_s + 1)
    dp = 1
    for i in range(n):
        # dp[j] |= dp[j - s[i]]
        dp |= dp << s[i]
    # precompute max up to i for all i
    # rather than for each t going back to the previous max
    # we need to know for every t what is the most we can fit into bag 1
    # hence below

    DP = [0] * (sum_s + 1)
    for i in range(sum_s + 1):
        if dp & (1 << i):
            DP[i] = i
        else:
            DP[i] = DP[i - 1]
    t = 0
    while True:
        if sum_s - DP[min(sum_s, M * t)] <= m * t:
            ans.append(t)
            break
        t += 1

os.write(1, "\n".join(map(str, ans)).encode())
