import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n = int(input())
    string = input().decode().rstrip()
    substring = []
    for i in range(n):
        while substring and string[substring[-1]] < string[i]:
            substring.pop()
        substring.append(i)

    substring_n = len(substring)
    substring_i = 0
    start_streak = None
    i = 0

    curr = "9"
    assert curr < "a"
    ok = True
    for i in range(n):
        if substring_i < substring_n and substring[substring_i] == i:
            idx = substring[substring_n - 1 - substring_i]
            if string[idx] < curr:
                ok = False
                break
            curr = string[idx]

            if start_streak is None:
                start_streak = 0
                subst_start = string[substring[substring_i]]
            elif start_streak == substring_i - 1:
                if subst_start == string[substring[substring_i]]:
                    start_streak += 1

            substring_i += 1

        else:
            if string[i] < curr:
                ok = False
                break
            curr = string[i]
    if ok:
        ans.append(str(substring_n - 1 - start_streak))

        # substring starts with zzz take away
    else:
        ans.append("-1")
os.write(1, "\n".join(ans).encode())
