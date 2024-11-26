# Programmers150369.py
def solution(cap, n, deliveries, pickups):
    ans = 0

    d_end, p_end = n - 1, n - 1
    while not (d_end == -1 and p_end == -1):
        while d_end != -1 and deliveries[d_end] == 0:
            d_end -= 1

        while p_end != -1 and pickups[p_end] == 0:
            p_end -= 1

        ans += (max(d_end, p_end) + 1) * 2

        curr = cap
        while d_end != -1 and curr:
            if deliveries[d_end] <= curr:
                curr -= deliveries[d_end]
                d_end -= 1
            else:
                deliveries[d_end] -= curr
                curr = 0

        curr = cap
        while p_end != -1 and curr:
            if pickups[p_end] <= curr:
                curr -= pickups[p_end]
                p_end -= 1
            else:
                pickups[p_end] -= curr
                curr = 0

    return ans
