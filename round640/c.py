import os
from io import BytesIO
from math import ceil

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


# want to find smallest x such that x - x//n = k
def solve(n, k):
    m = k
    M = 2 * k + 2
    while m < M:
        x = (m + M) // 2
        if x - x // n >= k:
            M = x
        else:
            m = x + 1
    return m


for _ in range(int(input())):
    n, k = map(int, input().split())
    if k < n:
        ans.append(str(k))
    else:
        ans.append(str(solve(n, k)))
os.write(1, "\n".join(ans).encode())
