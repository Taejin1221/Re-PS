# Baekoon30689.py
import sys
sys.setrecursionlimit(4 * 10 ** 6)
input = sys.stdin.readline

n, m = map(int, input().split())

maze = [input().rstrip() for _ in range(n)]
cost = [list(map(int, input().split())) for _ in range(n)]

stck = []
visited = [[False] * m for _ in range(n)]

def dfs(row, col):
    global ans

    (next_row, next_col) = (row, col)
    if maze[row][col] == 'U':
        next_row -= 1
    elif maze[row][col] == 'R':
        next_col += 1
    elif maze[row][col] == 'D':
        next_row += 1
    else:
        next_col -= 1

    if (0 <= next_row < n) and (0 <= next_col < m):
        # 다음 노드를 방문하지 않았다면 탐색한다.
        if not visited[next_row][next_col]:
            visited[next_row][next_col] = True
            stck.append((next_row, next_col))
            dfs(next_row, next_col)
            stck.pop()
        else:
            # 이미 방문한 노드라면 저장해둔 배열에 있는지 판단한다.
            min_cost = 0x3f3f3f3f
            idx = len(stck) - 1
            while idx >= 0 and not (stck[idx][0] == next_row and stck[idx][1] == next_col):
                # 사이클 판별을 하며 사이클에 속한 노드들 중 가장 설치 비용이 적은 수를 찾는다.
                back_row, back_col = stck[idx]
                min_cost = min(min_cost, cost[back_row][back_col])
                idx -= 1

            # 저장해둔 배열에 있다면
            if idx >= 0 and (stck[idx][0] == next_row and stck[idx][1] == next_col):
                # 점프대를 설치해준다. 이때 위의 로직에서는 가장 마지막 노드의 설치 비용은 고려하지 못한다. 따라서 이번에 고려해준다.
                ans += min(min_cost, cost[stck[idx][0]][stck[idx][1]])

ans = 0
for i in range(n):
    for j in range(m):
        if not visited[i][j]:
            visited[i][j] = True
            stck.append((i, j))
            dfs(i, j)
            stck.pop()

print(ans)
