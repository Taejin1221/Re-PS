# Baekjoon05972.py
import sys
input = sys.stdin.readline

from queue import PriorityQueue

n, m = map(int, input().split())

adj_list = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    adj_list[a].append((b, c))
    adj_list[b].append((a, c))

pq = PriorityQueue()
visited = [False] * (n + 1)

pq.put((0, 1))

ans = 0
while pq.qsize():
    cost, curr_v = pq.get()

    if curr_v == n:
        ans = cost
        break

    if not visited[curr_v]:
        visited[curr_v] = True
        for adj_v, dis in adj_list[curr_v]:
            if not visited[adj_v]:
                pq.put((cost + dis, adj_v))

print(ans)
