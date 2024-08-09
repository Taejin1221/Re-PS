# Baekjoon15565.py
import sys
input = sys.stdin.readline

INF = 10 ** 9

n, k = map(int, input().split())
dolls = list(map(int, input().split()))

ans = INF
leftIdx, currLion = 0, 0
for rightIdx in range(n):
	if (dolls[rightIdx] == 1):
		currLion += 1

	while (currLion >= k):
		ans = min(ans, rightIdx - leftIdx + 1)
		if (dolls[leftIdx] == 1):
			currLion -= 1
		leftIdx += 1

print(ans if ans != INF else -1)