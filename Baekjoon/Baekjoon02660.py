# Baekjoon02660.py
import sys
input = sys.stdin.readline

INF = 0x3f3f3f3f

n = int(input())

adj_mat = [[INF for _ in range(n + 1)] for _ in range(n + 1)]

for i in range(1, n + 1):
    adj_mat[i][i] = 0

a, b = map(int, input().split())
while not (a == -1 and b == -1):
    adj_mat[a][b] = 1
    adj_mat[b][a] = 1

    a, b = map(int, input().split())

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j])

friend_list = [[] for _ in range(n + 1)]
for i in range(1, n + 1):
    score = max(adj_mat[i][1:])

    friend_list[score].append(i)

ans = 0
while ans < n and len(friend_list[ans]) == 0:
    ans += 1

print(ans, len(friend_list[ans]))
print(*friend_list[ans])
