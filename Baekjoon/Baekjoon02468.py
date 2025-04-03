# Baekjoon02468.py
import sys
input = sys.stdin.readline

sys.setrecursionlimit(1_000_000)

MOVES = [(-1, 0), (0, 1), (1, 0), (0, -1)]

n = int(input())

area = [list(map(int, input().split())) for _ in range(n)]

def get_safe_area(rain):
    visited = [[False] * n for _ in range(n)]

    def dfs(curr):
        for i, j in MOVES:
            new_row, new_col = curr[0] + i, curr[1] + j

            if (0 <= new_row < n) and (0 <= new_col < n):
                if not visited[new_row][new_col] and area[new_row][new_col] > rain:
                    visited[new_row][new_col] = True
                    dfs((new_row, new_col))

    result = 0
    for i in range(n):
        for j in range(n):
            if not visited[i][j] and area[i][j] > rain:
                visited[i][j] = True
                dfs((i, j))

                result += 1

    return result

ans = 0
for i in range(0, 101):
    ans = max(ans, get_safe_area(i))

print(ans)
