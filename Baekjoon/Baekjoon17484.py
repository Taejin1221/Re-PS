# Baekjoon17484.py
MOVES = [-1, 0, 1]

n, m = map(int, input().split())

mat = [list(map(int, input().split())) for _ in range(n)]

def dfs(row, col, prev, curr):
    if row == n - 1:
        return curr

    result = 0x3f3f3f3f

    new_row = row + 1
    for i in range(len(MOVES)):
        new_col = col + MOVES[i]
        if prev != i and (0 <= new_row < n and 0 <= new_col < m):
            result = min(result, dfs(new_row, new_col, i, curr + mat[new_row][new_col]))

    return result

ans = 0x3f3f3f3f
for i in range(m):
    ans = min(ans, dfs(0, i, -1, mat[0][i]))

print(ans)
