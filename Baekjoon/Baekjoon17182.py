# Baekjoon17182.py
import sys
input = sys.stdin.readline

n, s = map(int, input().split())
adj_mat = [list(map(int, input().split())) for _ in range(n)]

for k in range(n):
    for i in range(n):
        for j in range(n):
            if i != j:
                adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j])

ans = 0x3f3f3f3f
visited = [False] * n

def solve(order):
    global ans
    if len(order) == n:
        result = 0
        for i in range(n - 1):
            result += adj_mat[order[i]][order[i + 1]]
        ans = min(ans, result)
    else:
        for i in range(n):
            if not visited[i]:
                visited[i] = True
                order.append(i)
                solve(order)
                order.pop()
                visited[i] = False

visited[s] = True
solve([s])

print(ans)
