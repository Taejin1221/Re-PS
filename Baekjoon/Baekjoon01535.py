# Baekjoon01535.py
import sys
input = sys.stdin.readline

n = int(input())
hp = list(map(int, input().split()))
happy = list(map(int, input().split()))

dp = [ 0 for _ in range(100) ]
for i in range(n):
	for j in range(99, -1, -1):
		if (dp[j] != 0 and j + hp[i] < 100):
			dp[j + hp[i]] = max(dp[j + hp[i]], dp[j] + happy[i])

	if (hp[i] < 100):
		dp[hp[i]] = max(dp[hp[i]], happy[i])

print(max(dp))