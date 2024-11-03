# Baekjoon01240-2.py
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

adj_list = [ [] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b, c = map(int, input().split())
    adj_list[a].append((b, c))
    adj_list[b].append((a, c))

def dfs(me, mom, target):
    if me == target:
        return 0

    for adj, cost in adj_list[me]:
        if adj != mom:
            result = dfs(adj, me, target)
            if result != -1:
                return result + cost

    return -1

for _ in range(m):
    a, b = map(int, input().split())

    print(dfs(a, 0, b))
