import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input().strip()
    C = "bcd"
    V = "ae"
    for c in C:
        for v in V:
            s = s.replace(c + v, "." + c + v)

    print(s[1:])
