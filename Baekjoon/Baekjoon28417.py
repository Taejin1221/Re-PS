# Baekjoon28417.py
import sys
input = sys.stdin.readline

n = int(input())

ans = 0
for _ in range(n):
    scores = list(map(int, input().split()))
    run = scores[:2]
    trick = scores[2:]

    score = max(run) + sum(sorted(trick, reverse=True)[:2])

    ans = max(ans, score)

print(ans)
