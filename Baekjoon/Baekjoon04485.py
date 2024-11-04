# Baekjoon04485.py
import sys
input = sys.stdin.readline

from queue import PriorityQueue

MOVES = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def solve(t, n):
    cave = [list(map(int, input().split())) for _ in range(n)]

    pq = PriorityQueue()
    visited = [[False] * n for _ in range(n)]

    pq.put((cave[0][0], (0, 0)))

    ans = 0
    while pq.not_empty:
        cost, (curr_row, curr_col) = pq.get()
        if curr_row == n - 1 and curr_col == n - 1:
            ans = cost
            break

        if not visited[curr_row][curr_col]:
            visited[curr_row][curr_col] = True

            for row, col in MOVES:
                next_row, next_col = curr_row + row, curr_col + col
                if (0 <= next_row < n) and (0 <= next_col < n):
                    if not visited[next_row][next_col]:
                        pq.put((cave[next_row][next_col] + cost, (next_row, next_col)))

    print(f"Problem {t}: {ans}")

t = 1
n = int(input())
while n != 0:
    solve(t, n)
    t += 1
    n = int(input())
