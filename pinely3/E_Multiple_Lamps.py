import sys


input = sys.stdin.readline


def how(p):
    # we want to turn on all of p
    state = 0  # All switches are initially off
    switch = 0  # No switches have been switched yet
    for i in range(1, 20):
        if (i in p) != bool(state & (1 << i)):
            switch |= 1 << i  # Switch the i-th switch
            for j in range(i, 20, i):
                state ^= 1 << j  # Toggle the j-th switch
    for i in range(5, 20):
        if max(p) <= i and len([x for x in p if x <= i]) <= i // 5:
            poss[i].add(switch & ((1 << (i + 1)) - 1))  # only care about first i


poss = {i: set() for i in range(5, 20)}

for i in range(1, 20):
    how((i,))
    for j in range(i + 1, 20):
        how((i, j))
        for k in range(j + 1, 20):
            how((i, j, k))

for _ in range(int(input())):
    n, m = map(int, input().split())

    if n >= 20 or n == 15:  # sqrt n > n//5 for sure
        print(n)
        print(" ".join(str(x + 1) for x in range(n)))
        for _ in range(m):
            input()
    elif n < 5:
        print(-1)
        for _ in range(m):
            input()
    else:
        children = [0] * (n + 1)
        for _ in range(m):
            i, j = [int(x) for x in input().split()]
            children[i] |= 1 << j

        for switch in poss[n]:
            for i in range(1, n + 1):
                if switch & (1 << i):
                    if children[i] & switch != children[i]:
                        break
            else:
                print(bin(switch).count("1"))
                print(" ".join(str(x) for x in range(1, n + 1) if switch & (1 << x)))
                break
        else:
            print(-1)
