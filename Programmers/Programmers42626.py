# Programmers42626.py
from queue import PriorityQueue

def solution(scoville, k):
    pq = PriorityQueue()
    for i in scoville:
        pq.put(i)

    ans = 0
    min_spicy = pq.get()
    while min_spicy < k and not pq.empty():
        min2_spicy = pq.get()

        mix = min_spicy + (min2_spicy * 2)
        pq.put(mix)
        ans += 1

        min_spicy = pq.get()

    if pq.empty():
        if min_spicy < k:
            return -1
        else:
            return ans
    else:
        return ans
