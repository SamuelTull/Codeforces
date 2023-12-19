# author: ankan2526

import sys, math, heapq, bisect, random, itertools

input = sys.stdin.readline
sys.setrecursionlimit(10**5)

ints = lambda: list(map(int, input().split()))


def gprint(ans=""):
    global t
    print(f"Case #{t+1}:", ans)


p = 10**9 + 7
inf = 10**20 + 7
ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
alpha = "abcdefghijklmnopqrstuvwxyz"

"""
"""

for t in range(int(input())):
    n = int(input())
    a = ints()
    ind = a.index(0)
    a = a[ind:] + a[:ind]
    ind = [0] * n
    b = [0]
    ans = n
    c = n
    for i in range(1, n):
        ind[a[i]] = i
        while a[i] < b[-1]:
            c -= b[-1] * (ind[b[-1]] - ind[b[-2]])
            b.pop()
        c += a[i] * (i - ind[b[-1]])
        ans = max(ans, c)
        b.append(a[i])
    print(ans)
