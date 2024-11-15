# Programmers214288.py
from queue import PriorityQueue

# mentors: 각 유형별 멘토 수
def simulation(mentors, k, reqs):
    wait_time = 0
    pq = [PriorityQueue() for _ in range(k + 1)]

    for start, time, type in reqs:
        prev_end_time = 0
        # 해당 유형의 멘토가 남아있지 않는 경우
        if pq[type].qsize() >= mentors[type]:
            prev_end_time = pq[type].get()
            if prev_end_time > start:
                wait_time += prev_end_time - start
        pq[type].put(max(prev_end_time, start) + time)

    return wait_time


def solution(k, n, reqs):
    mentors = [1] * (k + 1)

    ans = 0x3f3f3f3f
    def solve(curr, idx):
        nonlocal ans
        if curr > n:
            return

        if curr == n:
            ans = min(ans, simulation(mentors, k, reqs))
            return

        if idx > k:
            return

        for i in range(n - k + 1):
            mentors[idx] += i
            solve(curr + i, idx + 1)
            mentors[idx] -= i

    solve(k, 1)
    
    return ans