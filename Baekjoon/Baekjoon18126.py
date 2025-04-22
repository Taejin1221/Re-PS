import sys
sys.setrecursionlimit(10_000)
input = sys.stdin.readline


def dfs(me, mom, dis):
    global ans

    ans = max(ans, dis)
    for adj_v, adj_d in adj_list[me]:
        if adj_v != mom:
            dfs(adj_v, me, dis + adj_d)


n = int(input())

adj_list = [[] for _ in range(5_001)]
for _ in range(n - 1):
    a, b, c = map(int, input().split())

    adj_list[a].append((b, c))
    adj_list[b].append((a, c))

ans = 0
dfs(1, 0, 0)

print(ans)
