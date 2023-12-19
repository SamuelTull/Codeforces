import os
from io import BytesIO

from math import log2, floor

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

S = [0] * 32
for _ in range(int(input())):
    t, v = map(int, input().split())
    if t == 1:
        S[v] += 1
        while S[v] == 3 and v < 31:
            S[v] = 1
            v += 1
            S[v] += 1
    elif t == 2:
        if v == 0:
            ans.append("YES")
        else:
            i = floor(log2(v))
            while i >= 0 and v > 0:
                for j in range(S[i]):
                    if 2**i <= v:
                        v -= 2**i
                i -= 1
            ans.append("YES" if v == 0 else "NO")

os.write(1, "\n".join(ans).encode())
