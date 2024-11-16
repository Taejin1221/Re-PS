# Baekjoon01927.py
import sys
input = sys.stdin.readline

from queue import PriorityQueue

n = int(input())

pq = PriorityQueue()

for _ in range(n):
    num = int(input())

    if num == 0:
        print((pq.get() if pq.qsize() else 0))
    else:
        pq.put(num)
