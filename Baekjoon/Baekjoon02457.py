# Baekjoon02457.py
import sys
input = sys.stdin.readline

days = [ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 ]

# 미리 각 월까지의 일수 합을 구해놓음
month_sum = [ 0, 0 ]
for i in range(2, 13):
    month_sum.append(month_sum[-1] + days[i - 1])

# 3월 1일, 11월 30일
season = (month_sum[3] + 1, month_sum[11] + 30)

n = int(input())

flowers = []
for _ in range(n):
    a, b, c, d = map(int, input().split())
    # 입력과 동시에 총 일수로 계산
    flowers.append((month_sum[a] + b, month_sum[c] + d))
flowers.sort() # 꽃이 핀 날짜로 정렬

dp = [0x3f3f3f3f for _ in range(366)]
for i in range(n - 1, -1, -1):
    start, end = flowers[i]
    # 3월 1일 보다 일찍 지고, 11월 30일 보다 늦게 피는 꽃은 필요없음
    if (end < season[0] or season[1] < start):
        continue

    # 만약 현재 선택한 꽃이 11월 30일 이상까지 피어있다면 1
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
