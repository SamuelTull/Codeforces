import os
from io import BytesIO
from collections import deque

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


cases = int(input())

# count how many lights are switched by other lights
# any that are not, must be switched by the original
# see what is is after that
# everything else must be in a cycle
# can pick n of these to switch- can only turn off even number of lights
# if S[i] for i in cycle is odd - impossible.
# pick smallest n of these to switch - have to either start or end with i - for all i that is on.

for case_i in range(cases):
    n = int(input())
    s = [bool(int(x)) for x in input().decode().rstrip()]
    a = [int(x) - 1 for x in input().decode().rstrip().split()]
    print("NEW CASE", "\ns", s, "\na", a)

    count = [0] * n
    for x in a:
        count[x] += 1
    print("count", count)

    Q = deque([i for i in range(n) if count[i] == 0])
    done = [False] * n
    this = 0
    seen = set()
    while Q:
        i = Q.popleft()
        if i in seen:
            continue
        seen.add(i)
        if s[i]:
            # print("switching on ", i, "also switching", a[i])
            done[i] = True
            this += 1
            s[i] = False
            s[a[i]] = not s[a[i]]
            seen = set()
        else:
            Q.append(i)
    print("DONE", done)
    print("s", s)
    for i in range(n):
        if s[i] and not done[i]:
            # find cycle
            cycle = [i]
            j = a[i]
            while j != i:
                cycle.append(j)
                j = a[j]
                print("cycle", i, cycle)
                if len(cycle) > n:
                    assert False
