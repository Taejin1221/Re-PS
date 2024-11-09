# Programmers258711.py
import sys
sys.setrecursionlimit(10 ** 6)

MAX_NODE = 1_000_001

visited = [False] * MAX_NODE
adj_list = [[] for _ in range(MAX_NODE)]

def dfs(curr):
    if adj_list[curr]:
        next_node = adj_list[curr][0]
        if not visited[next_node]:
            visited[next_node] = True
            dfs(next_node)

def solution(edges):
    ans = [0, 0, 0, 0]

    n = 0
    is_node = [False] * MAX_NODE
    indegree, outdegree = [0] * MAX_NODE, [0] * MAX_NODE
    for u, v in edges:
        n = max(n, u, v)

        is_node[u] = True
        is_node[v] = True

        adj_list[u].append(v)
        outdegree[u] += 1
        indegree[v] += 1

    for i in range(1, n + 1):
        if indegree[i] == 0 and outdegree[i] >= 2:
            ans[0] = i
            for adj in adj_list[i]:
                indegree[adj] -= 1
            break

    stick, graph8 = [], []
    for i in range(1, n + 1):
        if is_node[i] and indegree[i] == 0 and outdegree[i] <= 1:
            stick.append(i)
        elif indegree[i] == 2 and outdegree[i] == 2:
            graph8.append(i)

    for i in stick:
        visited[i] = True
        dfs(i)
        ans[2] += 1

    for i in graph8:
        visited[i] = True
        visited[adj_list[i][0]] = True
        visited[adj_list[i][1]] = True

        dfs(adj_list[i][0])
        dfs(adj_list[i][1])

        ans[3] += 1

    visited[ans[0]] = True
    for i in range(1, n + 1):
        if is_node[i] and not visited[i]:
            visited[i] = True
            dfs(i)
            ans[1] += 1

    return ans