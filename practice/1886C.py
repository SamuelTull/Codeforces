import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


def arithmetic_sum(a, d, n):
    return n * (2 * a + (n - 1) * d) // 2


def bin_search(n, pos):
    # find the length of the substring that contains the nth char
    # find the position in this substring
    low = 1
    high = n
    while low < high:
        mid = (low + high) // 2
        if arithmetic_sum(n, -1, mid) < pos:
            low = mid + 1
        else:
            high = mid
    return (low - 1), pos - arithmetic_sum(n, -1, low - 1) - 1


for _ in range(int(input())):
    s = input().decode().rstrip()
    pos = int(input())
    n = len(s)
    n_rem, pos = bin_search(n, pos)
    S = [0]
    i = 1
    while n_rem and i < n:
        while n_rem and len(S) and s[S[-1]] > s[i]:
            S.pop()
            n_rem -= 1
        S.append(i)
        i += 1
    if pos < len(S):
        ans.append(s[S[pos]])
    else:
        ans.append(s[i + pos - len(S)])


os.write(1, "".join(ans).encode())
