# Baekjoon02056.py
import sys
input = sys.stdin.readline

from queue import PriorityQueue

n = int(input())

cost = [0] * (n + 1) # 노드의 수행 시간
indegree = [0] * (n + 1) # 노드의 내차수
adj_list = [[] for _ in range(n + 1)]
for curr in range(1, n + 1):
    temp = list(map(int, input().split()))

    cost[curr] = temp[0]
    for adj in temp[2:]:
        # 각 노드의 선행작업이 주어지기 때문에 선행작업이 나를 가리키도록 그래프를 만들어준다.
        adj_list[adj].append(curr)
        indegree[curr] += 1

pq = PriorityQueue()

# 내차수가 0인 노드들로부터 시작한다.
for i in range(1, n + 1):
    if indegree[i] == 0:
        pq.put((cost[i], i))

ans = [0] * (n + 1)
while pq.qsize():
    curr_cost, curr = pq.get()
    ans[curr] = curr_cost

    for adj in adj_list[curr]:
        indegree[adj] -= 1

        if indegree[adj] == 0:
            pq.put((curr_cost + cost[adj], adj))

print(max(ans))
