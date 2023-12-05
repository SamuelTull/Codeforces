import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

n_cases = int(input())
for _ in range(n_cases):
    n = int(input())
    segments = [tuple(map(int, input().decode().rstrip().split())) for _ in range(n)]
    print(segments)

os.write(1, "\n".join(ans).encode())
