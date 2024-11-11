# Baekjoon02665.py
import sys
from queue import PriorityQueue

input = sys.stdin.readline

MOVES = [(-1, 0), (0, 1), (1, 0), (0, -1)]

n = int(input())
room = [input().rstrip() for _ in range(n)]

pq = PriorityQueue()
pq.put((0, (0, 0))) # (거리, (행, 열))

visited = [[False] * n for _ in range(n)]

ans = 0
while pq:
    cost, (curr_r, curr_c) = pq.get()

    if curr_r == n - 1 and curr_c == n - 1:
        ans = cost
        break

    if not visited[curr_r][curr_c]:
        visited[curr_r][curr_c] = True

        for dr, dc in MOVES:
            next_r, next_c = curr_r + dr, curr_c + dc
            if (0 <= next_r < n) and (0 <= next_c < n):
                if not visited[next_r][next_c]:
                    # 다음 방문할 노드가 검은방이라면 거리에 1을 더해준다.
                    pq.put((cost + (0 if room[next_r][next_c] == '1' else 1), (next_r, next_c)))

print(ans)
