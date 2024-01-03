import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    L = sorted(map(int, input().split()))
    R = sorted(map(int, input().split()))
    C = sorted(map(int, input().split()))

    out = []
    l = 0
    r = 0
    stack = []
    while l < n or r < n:
        if l < n and L[l] < R[r]:
            stack.append(l)
            l += 1
        else:
            ll = stack.pop()
            out.append(R[r] - L[ll])
            r += 1
    out = sorted(out, reverse=True)
    print(sum(out[i] * C[i] for i in range(n)))
