import sys
input = sys.stdin.readline


def get_gcd(a, b):
    return (a if b == 0 else get_gcd(b, a % b))


for _ in range(int(input())):
    arr = list(map(int, input().split()))
    n = len(arr)

    ans = 1
    for i in range(n):
        for j in range(i + 1, n):
            ans = max(ans, get_gcd(max(arr[i], arr[j]), min(arr[i], arr[j])))

    print(ans)
