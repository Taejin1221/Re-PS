# Baekjoon04158.py
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
while (not (n is 0 and m is 0)):
    상근, 선영 = [], []
    for _ in range(n):
        상근.append(int(input()))

    for _ in range(m):
        선영.append(int(input()))

    ans, leftIdx, rightIdx = 0, 0, 0
    while (leftIdx < n and rightIdx < m):
        if (상근[leftIdx] == 선영[rightIdx]):
            leftIdx += 1
            rightIdx += 1
            ans += 1
        elif (상근[leftIdx] > 선영[rightIdx]):
            rightIdx += 1
        else:
            leftIdx += 1

    print(ans)

    n, m = map(int, input().split())