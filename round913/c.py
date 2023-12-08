import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


n_cases = int(input())
for _ in range(n_cases):
    C = [0] * 26
    n = int(input())
    for c in input().decode().rstrip():
        C[ord(c) - ord("a")] += 1
    most = max(C)
    ans.append(max(n % 2, most - (n - most)))

os.write(1, "\n".join(map(str, ans)).encode())
