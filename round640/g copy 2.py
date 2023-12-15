import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


# permutations = {}

# for _ in range(int(input())):
#     n = int(input())
#     print(permutations[n])


def find_permutations(out, n):
    if len(out) == n:
        return True, out
    for i in range(1, n + 1):
        if i in out:
            continue
        if out:
            if abs(out[-1] - i) not in [2, 3, 4]:
                continue
        out.append(i)
        valid, final = find_permutations(out, n)
        if valid:
            return True, final
        out.pop(-1)

    return False, -1


print("permutations = {")
for i in range(2, 50):
    _, out = find_permutations([], i)
    if out == -1:
        print(i, ": '-1',")
    else:
        print(i, ": '" + " ".join(map(str, out)) + "',")
print("}")
