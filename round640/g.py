import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


def find_start(n):
    out = [1, 3, 5]
    o = 5
    e = 0
    while o < n - 10 and e < n - 10:
        for _ in range(5):
            e += 2
            out.append(e)
        for _ in range(5):
            o += 2
            out.append(o)
    return out


def find_permutations(n):
    if len(out) == n:
        return True
    m = 1
    if out:
        m = max(1, out[-1] - 10)
    for i in range(m, n + 1):
        if i in out:
            continue
        if out:
            if abs(out[-1] - i) not in [2, 3, 4]:
                continue
        out.append(i)
        if find_permutations(n):
            return True
        out.pop(-1)
    return False


for _ in range(int(input())):
    n = int(input())
    if n <= 3:
        ans.append("-1")
        continue
    if n < 20:
        out = []
    else:
        out = find_start(n)
    find_permutations(n)
    ans.append(" ".join(map(str, out)))

os.write(1, "\n".join(ans).encode())
