# Baekjoon01446.py
import sys
input = sys.stdin.readline

n, target = map(int, input().split())

graph = [[] for _ in range(target + 1)]
for _ in range(n):
    s, e, d = map(int, input().split())
    if s <= target:
        graph[s].append((e, d))

shortest = [0x3f3f3f3f] * (target + 1)
shortest[0] = 0
for i in range(target + 1):
    if i != 0:
        shortest[i] = min(shortest[i], shortest[i - 1] + 1)

    for adj, dis in graph[i]:
        if adj <= target:
            shortest[adj] = min(shortest[adj], shortest[i] + dis)

print(shortest[target])
