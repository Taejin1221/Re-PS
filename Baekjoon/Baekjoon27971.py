# Baekjoon27971.py
import sys
input = sys.stdin.readline

from collections import deque

n, m, a, b = map(int, input().split())
delete = [False for _ in range(100_001)]

for _ in range(m):
    l, r = map(int, input().split())

    for i in range(l, r + 1):
        delete[i] = True

q = deque()
visited = [False for _ in range(100_001)]

q.append((0, 0))
visited[0] = True

ans = -1
while q:
    curr, time = q.popleft()
    if curr == n:
        ans = time
        break

    next_dog = curr + a
    if next_dog <= 100_000 and (not visited[next_dog]) and (not delete[next_dog]):
        visited[next_dog] = True
        q.append((next_dog, time + 1))

    next_dog = curr + b
    if next_dog <= 100_000 and (not visited[next_dog]) and (not delete[next_dog]):
        visited[next_dog] = True    
        q.append((next_dog, time + 1))

print(ans)
