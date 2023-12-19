import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []
for _ in range(int(input())):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    x = list(map(int, input().split()))
    minx = 31
    for i in range(q):
        if x[i] < minx:
            minx = x[i]
            for j in range(n):
                if a[j] % 2 ** x[i] == 0:
                    a[j] += 2 ** (x[i] - 1)

    ans.append(a)

os.write(1, "\n".join([" ".join((str(x) for x in a)) for a in ans]).encode())
