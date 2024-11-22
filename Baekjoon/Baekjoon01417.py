# Baekjoon01417.py
from queue import PriorityQueue

n = int(input())

dasom = int(input())

pq = PriorityQueue()
for _ in range(n - 1):
    temp = int(input())
    pq.put((-temp, temp))

ans = 0
while pq.qsize():
    _, top = pq.get()
    if dasom > top:
        break

    ans += 1
    dasom += 1
    if top >= 2:
        pq.put((-(top - 1), (top - 1)))

print(ans)
