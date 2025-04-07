# Baekjoon04963.py
import sys
input = sys.stdin.readline

MOVES = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]

def dfs(row, col):
    for r, c in MOVES:
        nextRow, nextCol = row + r, col + c

        if (0 <= nextRow < maxRow) and (0 <= nextCol < maxCol):
            if not visited[nextRow][nextCol] and adjMat[row][col]:
                visited[nextRow][nextCol] = True

                dfs(nextRow, nextCol)

maxCol, maxRow = map(int, input().split())
while (maxCol != 0 and maxRow != 0):
    ans = 0
    visited = [[False] * maxCol for _ in range(maxRow)]

    adjMat = [list(map(int, input().split())) for _ in range(maxRow)]

    for row in range(maxRow):
        for col in range(maxCol):
            if not visited[row][col] and adjMat[row][col]:
                visited[row][col] = True
                dfs(row, col)

                ans += 1

    print(ans)

    maxCol, maxRow = map(int, input().split())
