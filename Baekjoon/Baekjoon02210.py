# Baekjoon02210.py
board = []
for _ in range(5):
    board.append(list(map(int, input().split())))

moves = ((-1, 0), (0, 1),  (1, 0), (0, -1))

ans = 0
visited = { }

def dfs(currRow, currCol, size, num):
    if (size == 6):
        visited[num] = 1
    else:
        for move in moves:
            newRow, newCol = currRow + move[0], currCol + move[1]
            if ((0 <= newRow < 5) and (0 <= newCol < 5)):
                dfs(newRow, newCol, size + 1, num * 10 + board[newRow][newCol])

for i in range(5):
    for j in range(5):
        dfs(i, j, 1, board[i][j])

print(len(visited))