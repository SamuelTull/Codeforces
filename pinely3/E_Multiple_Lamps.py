import sys

input = sys.stdin.readline
from math import sqrt

poss = {}


def how(p):
    # we want to turn on all of p
    state = 0  # All switches are initially off
    switch = 0  # No switches have been switched yet
    for i in range(1, 20):
        if (i in p) != bool(state & (1 << i)):
            switch |= 1 << i  # Switch the i-th switch
            for j in range(i, 20, i):
                state ^= 1 << j  # Toggle the j-th switch
    return switch


for i in range(1, 20):
    poss[(i,)] = how((i,))
    for j in range(i + 1, 20):
        poss[(i, j)] = how((i, j))
        for k in range(j + 1, 20):
            poss[(i, j, k)] = how((i, j, k))

for _ in range(int(input())):
    n, m = map(int, input().split())
    children = [0] * (n + 1)
    for _ in range(m):
        i, j = [int(x) for x in input().split()]
        children[i] |= 1 << j
    if int(sqrt(n)) <= n // 5:
        print(n)
        print(" ".join(str(x + 1) for x in range(n)))
    else:
        found = False
        for p, switch in poss.items():
            if max(p) > n or len(p) > n // 5:
                continue
            switch &= (1 << (n + 1)) - 1
            child = 0
            for i in range(1, n + 1):
                if switch & (1 << i):
                    child |= children[i]
            if child & switch == child:
                print(bin(switch).count("1"))
                print(" ".join(str(x) for x in range(1, n + 1) if switch & (1 << x)))
                break
        else:
            print(-1)
