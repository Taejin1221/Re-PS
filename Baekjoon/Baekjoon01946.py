# Baekjoon01946.py
import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())

    scores = []
    for _ in range(n):
        scores.append(tuple(map(int, input().split())))
    scores.sort()

    ans = 1
    minInterviewScore = scores[0][1]
    for i in range(1, n):
        if (minInterviewScore > scores[i][1]):
            ans += 1
            minInterviewScore = scores[i][1]

    print(ans)
