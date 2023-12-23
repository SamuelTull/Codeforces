import sys

input = sys.stdin.readline
from math import sqrt

poss = {}


def how(p):
    # we want to turn on all of p
    state = [False] * 20
    switch = set()
    for i in range(1, 20):
        if (i in p) != state[i]:
            switch.add(i)
            for j in range(i, 20, i):
                state[j] = not state[j]
    return switch


for i in range(1, 20):
    poss[(i,)] = how((i,))
    for j in range(i + 1, 20):
        poss[(i, j)] = how((i, j))
        for k in range(j + 1, 20):
            poss[(i, j, k)] = how((i, j, k))


for _ in range(int(input())):
    n, m = map(int, input().split())
    children = {i: set() for i in range(n + 1)}
    for _ in range(m):
        i, j = [int(x) for x in input().split()]
        children[i].add(j)
    if int(sqrt(n)) <= n // 5:
        print(n)
        print(" ".join(str(x + 1) for x in range(n)))
    else:
        found = False
        for p, switch in poss.items():
            if max(p) > n or len(p) > n // 5:
                continue
            switch = switch & set(range(1, n + 1))
            if all(children[i] <= switch for i in switch):
                print(len(switch))
                print(" ".join(str(x) for x in switch))
                break
        else:
            print(-1)
