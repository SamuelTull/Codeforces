import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n = int(input())
    n, *nums = map(int, input().split())
    nums = list(map(int, input().split()))
    string = input().decode().rstrip()


os.write(1, "\n".join(ans).encode())
