import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


# for _ in range(int(input())):
#     n = int(input())
#     print(permutations[n])


def find_permutations(n):
    if n <= 3:
        return -1
    out = [1, 3, 5]
    o = 5
    e = 0
    while o < n or e < n:
        for i in range(5):
            e += 2
            out.append(e)
        for i in range(5):
            o += 2
            out.append(o)
    return out


print("permutations = {")
for i in range(11):
    out = find_permutations(i)
    if out == -1:
        print(i, ": '-1',")
    else:
        print(i, ": '" + " ".join(map(str, out)) + "',")
print("}")
