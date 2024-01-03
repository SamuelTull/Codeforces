import sys
from bisect import bisect_left

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    pairs = [tuple(map(int, input().split())) for _ in range(n)]
    A = sorted(pairs, key=lambda x: x[0])
    B = sorted(pairs, key=lambda x: x[1])

    ints = []

    ai = 0
    bi = 0

    #! replace len(ints) with running count

    ints = []
    ans = 0
    while ai < n and bi < n:
        if A[ai][0] < B[bi][1]:
            ints.append(A[ai])
            ai += 1
        else:
            idx = bisect_left(ints, B[bi])
            ans += len(ints) - idx
            ints.pop(idx)
            bi += 1
    print(ans)
