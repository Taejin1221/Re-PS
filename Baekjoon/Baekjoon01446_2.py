# Baekjoon01446_2.py
import sys
input = sys.stdin.readline

from queue import PriorityQueue

n, target = map(int, input().split())

adj_list = [[(i + 1, 1)] for i in range(target + 1)]
for _ in range(n):
    s, e, d = map(int, input().split())
    if s <= target:
        adj_list[s].append((e, d))

pq = PriorityQueue()
visited = [False] * (target + 1)

pq.put((0, 0))

ans = 0
while pq.qsize():
    curr_v, curr_d = pq.get()
    if curr_v == target:
        ans = curr_d
        break

    if not visited[curr_v]:
        visited[curr_v] = True
        for adj_v, adj_d in adj_list[curr_v]:
            pq.put((adj_v, curr_d + adj_d))

print(ans)
