import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    this = 0
    a, b = map(int, input().split())
    kx, ky = map(int, input().split())
    qx, qy = map(int, input().split())

    D = [a, b]
    K = set()
    Q = set()
    for opt in [0, 1]:
        for sx in [-1, 1]:
            for sy in [-1, 1]:
                dx = D[opt] * sx
                dy = D[1 - opt] * sy
                K.add((kx + dx, ky + dy))
                Q.add((qx + dx, qy + dy))

    ans.append(len(Q & K))

os.write(1, "\n".join(map(str, ans)).encode())
