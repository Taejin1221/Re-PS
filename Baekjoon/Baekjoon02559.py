# Baekjoon02559.py
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))

ans = -0x3f3f3f3f
curr = [0, 0]
for i in range(n):
    curr[0] += arr[i]
    curr[1] += 1

    if curr[1] == k:
        ans = max(ans, curr[0])
        curr[0] -= arr[i - (k - 1)]
        curr[1] -= 1

print(ans)
