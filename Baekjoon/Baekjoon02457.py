# Baekjoon02457.py
import sys
input = sys.stdin.readline

days = [ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 ]

month_sum = [ 0, 0 ]
for i in range(2, 13):
    month_sum.append(month_sum[-1] + days[i - 1])
season = (month_sum[3] + 1, month_sum[11] + 30)

n = int(input())

flowers = []
for _ in range(n):
    a, b, c, d = map(int, input().split())
    flowers.append((month_sum[a] + b, month_sum[c] + d))
flowers.sort()

dp = [0x3f3f3f3f for _ in range(366)]
for i in range(n - 1, -1, -1):
    start, end = flowers[i]
    if (end < season[0] or season[1] < start):
        continue

    if (season[1] < end):
        dp[start] = 1
    else:
        for j in range(start, end + 1):
            dp[start] = min(dp[start], dp[j] + 1)

ans = min(dp[1:season[0] + 1])
if (ans == 0x3f3f3f3f):
    print(0)
else:
    print(ans)
