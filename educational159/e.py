import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
ss = [input().decode().rstrip() for _ in range(n)]

starts = {}
ends = {}

BASE = 27

for s in ss:
    prefix_hash = 0
    suffix_hash = 0

    for i in range(len(s)):
        prefix_hash = prefix_hash * BASE + (ord(s[i]) - ord("a") + 1)
        suffix_hash = suffix_hash * BASE + (ord(s[-i - 1]) - ord("a") + 1)
        starts[prefix_hash] = starts.get(prefix_hash, 0) + 1
        ends[suffix_hash] = ends.get(suffix_hash, 0) + 1


ans = 2 * n * sum(len(s) for s in ss)
for s in starts:
    if s in ends:
        ans -= 2 * starts[s] * ends[s]


print(ans)
