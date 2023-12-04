cases = int(input())

for _ in range(cases):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    if k == 1:
        # return yes if sorted
        for i in range(1, n):
            if arr[i] < arr[i - 1]:
                print("NO")
                break
        else:
            print("YES")

    else:
        print("YES")
