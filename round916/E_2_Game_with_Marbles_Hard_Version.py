import sys

input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    ss = sorted(range(n), key=lambda i: a[i] + b[i], reverse=True)
    A = 0
    B = 0
    for i in range(n):
        idx = ss[i]
        if i % 2 == 0:
            A += a[idx] - 1
        else:
            B += b[idx] - 1

    print(A - B)
