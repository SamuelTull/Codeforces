# https://codeforces.com/problemset/problem/1872/F
# Sell any animal that is "Not Scary" i.e nothing fears it
# this may make mroe animals "Not Scary"
# eventually only left with cycles
# will get double from all but the last one sold
# so sell the cheapest one last !
# all we need to do is find any cycles and find the cheapest in this cycle
# With this solution we get 2*c for all but the cheapest in each cycle
# ans = 2 * sum(c) - sum(smallest ones)
# have to return order - not just the sum
# start with the ones that are "not scary"


import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    c = list(map(int, input().split()))

    this = 2 * sum(c)
    SEEN = [False] * n
    cycles = []
    for i in range(n):
        if SEEN[i]:
            continue
        SEEN[i] = True
        cycle = [i]
        curr = a[i] - 1
        while not SEEN[curr]:
            SEEN[curr] = True
            cycle.append(curr)
            curr = a[curr] - 1
        if curr in cycle:
            cycles.append(cycle[cycle.index(curr) :])
    min_list = []

    for cycle in cycles:
        this -= min(c[i] for i in cycle)
    ans.append(this)

os.write(1, "\n".join(map(str, ans)).encode())
