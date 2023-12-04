import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

# C(A,B) = C(B,A)
# 2*C(A,B) for A(1-n) B(a+1 - n)
# if the last letter of a is equal to the first letter of b then remove

cache = {}


def C(A, B):
    if len(A) == 0:
        return len(B)
    if len(B) == 0:
        return len(A)
    if (A, B) in cache:
        return cache[(A, B)]
    if A[0] == B[-1]:
        return C(A[1:], B[:-1])
    cache[(A, B)] = len(A) + len(B)
    return cache[(A, B)]


n = int(input())
nums = [input().decode().rstrip() for _ in range(n)]


s = 0
for numi in nums:
    for numj in nums:
        s += C(numi, numj)


print(s)
