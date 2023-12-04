# A. Tales of a Sort
# https://codeforces.com/contest/1856/problem/A


# if max(array) is not in final position
# we need max(array)
# else look at second max - if not second last

cases = int(input())

for _ in range(cases):
    N = int(input())
    arr = list(map(int, input().split()))
    arr_sorted = sorted(arr)
    for i in range(N - 1, 0, -1):  # dont need to check final element
        if arr[i] != arr_sorted[i]:
            print(arr_sorted[i])
            break
    else:
        print(0)
