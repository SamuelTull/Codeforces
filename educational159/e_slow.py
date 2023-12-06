import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
ss = [input().decode().rstrip() for _ in range(n)]

starts = {}
ends = {}

for i in range(n):
    for j in range(len(ss[i])):
        if ss[i][: j + 1] not in starts:
            starts[ss[i][: j + 1]] = 1
        else:
            starts[ss[i][: j + 1]] += 1
        if ss[i][: -j - 2 : -1] not in ends:
            ends[ss[i][: -j - 2 : -1]] = 1
        else:
            ends[ss[i][: -j - 2 : -1]] += 1


ans = 2 * n * sum(len(s) for s in ss)
for s in starts:
    if s in ends:
        ans -= 2 * starts[s] * ends[s]


print(ans)
