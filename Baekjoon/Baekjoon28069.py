# Baekjoon28069.py
from collections import deque

n, k = map(int, input().split())

q = deque()
visited = [False for _ in range(n + 1)]

q.append((0, 0))
visited[0] = True
while q:
    vertex, distance = q.popleft()

    if vertex == n:
        ans = distance
        break

    next_v = vertex + 1
    if next_v <= n and not visited[next_v]:
        visited[next_v] = True
        q.append((next_v, distance + 1))

    next_v = vertex + vertex // 2
    if next_v <= n and not visited[next_v]:
        visited[next_v] = True
        q.append((next_v, distance + 1))

print("minigimbob" if ans <= k else "water")
