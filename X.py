import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

# cases = int(input())
# for _ in range(cases):
# nums = map(int, input().split())
# string = input().decode().rstrip()


os.write(1, "\n".join(ans).encode())
