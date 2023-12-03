# work out how many tasks there are to do
# 1. as many days with 2 tasks as possible/necessary
# 2. day with 1 task if possible and necessary
# 3. as many days with 0 tasks as necessary
# question says guaranteed to be possible!

from math import ceil

n_tests = int(input())
for _ in range(n_tests):
    n, p, l, t = map(int, input().split())
    tasks = (n - 1) // 7 + 1
    lessons = min(tasks // 2, ceil(p / (l + 2 * t)))
    p -= lessons * (l + 2 * t)
    if p > 0 and tasks % 2:
        lessons += 1
        p -= l + t
    if p > 0:
        lessons += ceil(p / l)
    print(n - lessons)
