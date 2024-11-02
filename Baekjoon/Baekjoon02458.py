# Baekjoon02458.py
import sys
input = sys.stdin.readline

visited = []

def dfs(adj_list, arr, curr):
    for adj in adj_list[curr]:
        if not visited[adj]:
            arr[adj] += 1
            visited[adj] = True
            dfs(adj_list, arr, adj)


n, m = map(int, input().split())

adj_list1 = [ [] for _ in range(n + 1) ]
adj_list2 = [ [] for _ in range(n + 1) ]

for _ in range(m):
    a, b = map(int, input().split())
    adj_list1[a].append(b)
    adj_list2[b].append(a)

small = [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    visited = [False for _ in range(n + 1)]

    visited[i] = True
    dfs(adj_list1, small, i)

big = [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    visited = [False for _ in range(n + 1)]

    visited[i] = True
    dfs(adj_list2, big, i)

ans = 0
for i in range(1, n + 1):
    if small[i] + big[i] == (n - 1):
        ans += 1

print(ans)
