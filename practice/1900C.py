# https://codeforces.com/contest/1900/problem/C
# original solution - find number of changes needed to get to leaf from node i
# much faster to record number of changes needed to get to node from root
# Not 100% sure why, as both require fully traversing the tree and will have same O?
# Guessing fewer recursive calls
# in tests 1 is faster? but wasnt accepted by codeforces
import time
from collections import deque

cases = int(input())


def solve_1(i):
    # number of changes needed to get to leaf from node i
    # cache not needed because of the tree structures
    if L[i] == -1:
        if R[i] == -1:
            return 0
        return solve_1(R[i]) + (S[i] != "R")
    if R[i] == -1:
        return solve_1(L[i]) + (S[i] != "L")
    return min(solve_1(L[i]) + (S[i] != "L"), solve_1(R[i]) + (S[i] != "R"))


for _ in range(cases):
    n = int(input())
    S = input()
    L = [0] * n
    R = [0] * n
    for i in range(n):
        l, r = map(int, input().split())
        L[i] = l - 1
        R[i] = r - 1

    # solution 1 - find number of changes needed to get to leaf from node i
    start = time.time()
    print(solve_1(0), time.time() - start)

    # solution 2 - find number of changes needed to get to node from root
    start = time.time()
    ans = [0] * n
    Q = deque()
    Q.append(0)
    best = 1e10
    while Q:
        i = Q.popleft()
        if L[i] != -1:
            Q.append(L[i])
            ans[L[i]] = ans[i] + (S[i] != "L")
        if R[i] != -1:
            Q.append(R[i])
            ans[R[i]] = ans[i] + (S[i] != "R")
        if L[i] == -1 and R[i] == -1:
            best = min(best, ans[i])

    print(best, time.time() - start)
