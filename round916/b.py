import sys

input = sys.stdin.readline

for _ in range(int(input())):
    this = []
    n, k = map(int, input().split())
    for i in range(n - k, n + 1):
        this.append(i)
    for i in range(n - k - 1, 0, -1):
        this.append(i)

    print(" ".join(map(str, this)))
