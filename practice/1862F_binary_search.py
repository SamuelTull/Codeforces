import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


def canPartition(C1, C2):
    dp = [False] * (C1 + 1)
    dp[0] = True

    for weight in s:
        for j in range(C1, weight - 1, -1):
            dp[j] = dp[j] or dp[j - weight]

    for i in range(C1, -1, -1):
        if dp[i]:
            return sum_s - i <= C2


for _ in range(int(input())):
    w, f = map(int, input().split())
    m, M = min(w, f), max(w, f)
    n = int(input())
    s = list(map(int, input().split()))
    len_s = len(s)
    sum_s = sum(s)
    lo = sum_s // (w + f)
    hi = sum_s // M + 1
    while lo < hi:
        mid = int((lo + hi) / 2)
        if canPartition(m * mid, M * mid):
            hi = mid
        else:
            lo = mid + 1
    ans.append(hi)
os.write(1, "\n".join(map(str, ans)).encode())
