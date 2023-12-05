import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

cases = int(input())
for _ in range(cases):
    n = int(input())
    if n == 0:
        ans.append(0)
        continue
    if n < 10:
        ans.append(3)
        continue
    dig_sum = sum(map(int, str(n)))
    print(n, dig_sum)

    # triples that sum to n


os.write(1, "\n".join(ans).encode())
