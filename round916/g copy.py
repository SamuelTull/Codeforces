import os
from io import BytesIO
import bisect

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    open_ = {}
    closed = []
    cnt = 0

    total_a = 0
    total_b = 1

    for i in range(2 * n):
        num = nums[i] - 1
        cnt += 1
        if num not in open_:
            open_[num] = i
        else:
            i_prev = open_[num]  # first time we see this node
            del open_[num]

            idx = len(closed) - 1
            while idx >= 0 and i_prev < closed[idx]:
                cnt -= 2
                idx -= 1
            closed = closed[: idx + 1]

            bisect.insort(closed, i_prev)

            if len(open_) == 0:
                total_a += 1
                total_b *= cnt

                open_ = {}
                cnt = 0
                closed = []

    ans.append(str(total_a) + " " + str(total_b))

os.write(1, "\n".join(ans).encode())
