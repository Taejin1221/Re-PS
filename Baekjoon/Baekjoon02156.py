# Baekjoon02156.py
n = int(input())
wine = [int(input()) for _ in range(n)]

dp = [
    [0 for _ in range(n)],
    [0 for _ in range(n)]
]
dp[0][0] = dp[1][0] = wine[0]

ans = wine[0]
if n > 1:
    dp[0][1] = wine[1]
    dp[1][1] = wine[0] + wine[1]
    ans = max(ans, dp[0][1], dp[1][1])

    for i in range(2, n):
        if i > 2:
            dp[0][i] = max(dp[0][i - 2], dp[1][i - 2], dp[0][i - 3], dp[1][i - 3]) + wine[i]
        else:
            dp[0][i] = max(dp[0][i - 2], dp[1][i - 2]) + wine[i]
        dp[1][i] = dp[0][i - 1] + wine[i]

        ans = max(ans, dp[0][i], dp[1][i])

print(ans)
