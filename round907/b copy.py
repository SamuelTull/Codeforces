import os
from io import BytesIO


def find_max_pow(x):
    low = 0
    high = 30
    while low < high:
        mid = (low + high) // 2
        if x % (2**mid) == 0:
            low = mid + 1
        else:
            high = mid
    return low - 1


input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []
for _ in range(int(input())):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    a = sorted(((a[i], i) for i in range(n)), reverse=True)
    x = list(map(int, input().split()))
    pows = [find_max_pow(a[i][0]) for i in range(n)]
    mult = [a[i][0] / (2 ** pows[i]) for i in range(n)]
    for i in range(q):
        for j in range(n):
            if pows[j] >= x[i]:
                mult[j] = (2 ** (pows[j] - x[i] + 1)) * mult[j] + 1
                pows[j] = x[i] - 1
            else:
                break
    ans.append([0] * n)
    for i in range(n):
        ans[-1][a[i][1]] = mult[i] * (2 ** pows[i])


os.write(1, "\n".join([" ".join((str(int(x)) for x in a)) for a in ans]).encode())
