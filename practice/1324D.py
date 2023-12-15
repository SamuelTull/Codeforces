import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
lst = [a[i] - b[i] for i in range(n)]
lst.sort()
ll = 0
rr = n - 1

ans = 0
while ll < rr:
    if lst[ll] > -lst[rr]:
        ans += rr - ll
        rr -= 1
    else:
        ll += 1

os.write(1, str(ans).encode())
