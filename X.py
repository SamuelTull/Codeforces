import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).read().splitlines()
ans = []

# n = int(input())
# nums = map(int, input().split())
# string = input().decode().rstrip()


os.write(1, "\n".join(ans).encode())
