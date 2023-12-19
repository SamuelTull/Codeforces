import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    children = [[] for _ in range(n)]
    N = [0] * n
    P = [0] * n
    for i in range(n - 1):
        children[nums[i] - 1].append(i + 1)
    Q = [0]
    while Q:
        node = Q.pop()
        if N[node] == 0:
            N[node] = 1
            Q.append(node)
            for child in children[node]:
                Q.append(child)

        else:  # all of children have been processed
            mn = 0  # max number of nodes from child
            xp = 0  # pairs that the max child can make
            for child in children[node]:
                N[node] += N[child]
                if N[child] > mn:
                    mn = N[child]
                    xp = P[child]
            if mn <= (N[node] - 1 - mn):
                # can pair all nodes with a node from a different child
                P[node] = (N[node] - 1) // 2
            else:
                # use the pairs from the max child and pair as many of the rest as possible
                P[node] = min((N[node] - 1) // 2, N[node] - 1 - mn + xp)

    ans.append(str(P[0]))
os.write(1, "\n".join(ans).encode())


