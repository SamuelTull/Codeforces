# Cover in Water
# https://codeforces.com/contest/1900/problem/A

# if we have a gap size 3, infinite water source
# with only 2 placed
# otherwise have to fill all

from collections import defaultdict

cases = int(input())

for _ in range(cases):
    n = int(input())
    s = input()
    gaps = defaultdict(int)
    curr = 0
    for i in range(n):
        if s[i] == ".":
            curr += 1
        else:
            gaps[curr] += 1
            curr = 0
    gaps[curr] += 1

    if max(gaps.keys()) >= 3:
        print(2)
    else:
        print(sum(k * v for k, v in gaps.items()))
