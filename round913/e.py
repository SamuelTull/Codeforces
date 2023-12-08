import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

POSS = {
    0: 1,
    1: 3,
    2: 6,
    3: 10,
    4: 15,
    5: 21,
    6: 28,
    7: 36,
    8: 45,
    9: 55,
}
cases = int(input())
for _ in range(cases):
    this = 1
    for dig in input().decode().rstrip():
        this *= POSS[int(dig)]
    ans.append(str(this))


os.write(1, "\n".join(ans).encode())
