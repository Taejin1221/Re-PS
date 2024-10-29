# Baekjoon01389.py
import sys
input = sys.stdin.readline

from collections import deque

n, m = map(int, input().split())
adj_list = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())

    adj_list[a].append(b)
    adj_list[b].append(a)

bacon_number = [1_000_000_007 for _ in range(n + 1)]
for i in range(1, n + 1):
    curr_bacon = 0

    q = deque()
    visited = [False for _ in range(n + 1)]

    q.append((i, 0))
    visited[i] = True

    while (q):
        curr, dis = q.popleft()
        curr_bacon += dis

        for adj in adj_list[curr]:
            if (not visited[adj]):
                visited[adj] = True
                q.append((adj, dis + 1))

    bacon_number[i] = curr_bacon

ans = 0
for i in range(1, n + 1):
    if (bacon_number[ans] > bacon_number[i]):
        ans = i

print(ans)
