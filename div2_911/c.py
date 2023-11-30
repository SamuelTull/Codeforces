cases = int(input())


def DP(i):
    # number of changes needed given we are at node i
    if i in cache:
        return cache[i]
    if L[i] == -1 and R[i] == -1:
        return 0
    ans = 1e10
    if R[i] != -1:
        ans = min(ans, DP(R[i]) + (S[i] != "R"))
    if L[i] != -1:
        ans = min(ans, DP(L[i]) + (S[i] != "L"))
    cache[i] = ans
    return ans


for _ in range(cases):
    cache = {}
    n = int(input())
    S = input()
    L = {}
    R = {}
    for i in range(n):
        l, r = map(int, input().split())
        L[i] = l - 1
        R[i] = r - 1
    print(DP(0))
