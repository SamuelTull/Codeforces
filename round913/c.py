import os
from io import BytesIO
from collections import Counter

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

n_cases = int(input())
for _ in range(n_cases):
    n = int(input())
    c = Counter(input().decode().rstrip())
    most = c.most_common(1)[0][1]
    ans.append(max(n % 2, most - (n - most)))


os.write(1, "\n".join(map(str, ans)).encode())
