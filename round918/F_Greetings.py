import sys
import bisect

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    pairs = [tuple(map(int, input().split())) for _ in range(n)]
    pairs = sorted(pairs, key=lambda x: x[1])
    seen = []
    ans = 0

    for i in range(n):
        a, b = pairs[i]
        idx = bisect.bisect_left(seen, a)
        ans += i - idx
        seen.insert(idx, a)
    print(ans)
