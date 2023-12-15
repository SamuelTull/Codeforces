import os
from io import BytesIO
import bisect
from collections import deque

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
lst = deque([(b[0] - a[0])])
ans = 0
for i in range(1, n):
    curr = a[i] - b[i]
    ans += bisect.bisect_left(lst, curr)
    lst.insert(bisect.bisect_left(lst, -curr), -curr)

os.write(1, str(ans).encode())
