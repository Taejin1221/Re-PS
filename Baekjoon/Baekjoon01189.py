# Baekjoon01189.py
moves = ((-1, 0), (0, 1),  (1, 0), (0, -1))

r, c, k = map(int, input().split())

board = []
for _ in range(r):
    board.append(input())

ans = 0
visited = [[False for _ in range(c)] for _ in range(r)]

def dfs(currRow, currCol, size):
    if (currRow == 0 and currCol == (c - 1) and size == k):
        global ans
        ans += 1
    else:
        for dr, dc in moves:
            newRow, newCol = currRow + dr, currCol + dc
            if ((0 <= newRow < r) and (0 <= newCol < c)):
                if (not visited[newRow][newCol] and board[newRow][newCol] != 'T'):
                    visited[newRow][newCol] = True
                    dfs(newRow, newCol, size + 1)
                    visited[newRow][newCol] = False

visited[r - 1][0] = True
dfs(r - 1, 0, 1)

print(ans)