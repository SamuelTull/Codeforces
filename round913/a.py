import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
n = int(input())

cache = {}

out = []

for _ in range(n):
    rook = input().decode().rstrip()
    if rook not in cache:
        ans = [i + rook[1] for i in "abcdefgh" if i != rook[0]] + [
            rook[0] + i for i in "12345678" if i != rook[1]
        ]
        cache[rook] = ans
    out += cache[rook]


os.write(1, "\n".join(out).encode())
