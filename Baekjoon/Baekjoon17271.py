MOD = 1_000_000_007

n, m = map(int, input().split())

dp = [1]
for i in range(1, n + 1):
    dp.append(dp[i - 1])
    if i >= m:
        dp[i] += dp[i - m]
    dp[i] %= MOD

print(dp[n])
