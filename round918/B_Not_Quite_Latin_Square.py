import sys

input = sys.stdin.readline

for _ in range(int(input())):
    for _ in range(3):
        s = input()
        if "?" in s:
            for c in "ABC":
                if c not in s:
                    print(c)
