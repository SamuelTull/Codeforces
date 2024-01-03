import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    n, *nums = map(int, input().split())
    nums = list(map(int, input().split()))
    string = input().decode().rstrip()
