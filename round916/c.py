import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    this = 0
    cum_sum = 0
    max_b = 0
    for i in range(min(n, k)):
        cum_sum += a[i]
        max_b = max(max_b, b[i])

        this = max(this, (k - (i + 1)) * max_b + cum_sum)
    ans.append(str(this))

os.write(1, "\n".join(ans).encode())
