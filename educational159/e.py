import os
from io import BytesIO
import random

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
ss = [input().decode().rstrip() for _ in range(n)]

starts = {}
ends = {}


MOD_9 = [10**9 + 7, 10**9 + 9, 10**9 + 21, 10**9 + 33, 10**9 + 87]
MOD, MOD2 = random.sample(MOD_9, 2)
# MOD_18 = [10**18 + 61, 10**18 + 63, 10**18 + 91, 10**18 + 103, 10**18 + 123]
# MOD = random.choice(MOD_18)
BASE = random.randint(27, 100)
BASE2 = random.randint(27, 100)

for s in ss:
    prefix_hash = 0
    prefix_hash1 = 0
    suffix_hash = 0
    suffix_hash1 = 0

    for i in range(len(s)):
        prefix_hash = (prefix_hash * BASE + (ord(s[i]) - ord("a") + 1)) % MOD
        prefix_hash1 = (prefix_hash1 * BASE2 + (ord(s[i]) - ord("a") + 1)) % MOD2
        suffix_hash = (suffix_hash * BASE + (ord(s[-i - 1]) - ord("a") + 1)) % MOD
        suffix_hash1 = (suffix_hash1 * BASE2 + (ord(s[-i - 1]) - ord("a") + 1)) % MOD2
        pre = prefix_hash * (10**9 + 81) + prefix_hash1
        suf = suffix_hash * (10**9 + 81) + suffix_hash1
        starts[pre] = starts.get(pre, 0) + 1
        ends[suf] = ends.get(suf, 0) + 1


ans = 2 * n * sum(len(s) for s in ss)
for s in starts:
    if s in ends:
        ans -= 2 * starts[s] * ends[s]


print(ans)
