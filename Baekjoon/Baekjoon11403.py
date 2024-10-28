# Baekjoon11403.py
import sys, copy
input = sys.stdin.readline

n = int(input())
adjMat = [list(map(int, input().split())) for _ in range(n)]

ans = copy.deepcopy(adjMat)
for k in range(n):
    for i in range(n):
        for j in range(n):
            if (ans[i][k] and ans[k][j]):
                ans[i][j] = 1

for a in ans:
    for b in a:
        print(b, end=' ')
    print()
