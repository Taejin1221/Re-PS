# Programmers150365.py
from collections import deque

INSTS = "dlru" # 사전순 명령어
MOVES = [(1, 0), (0, -1), (0, 1), (-1, 0)] # 사전순 이동 순서

# (x, y) -> (r, c)
def solution(n, m, start_r, start_c, target_r, target_c, target_t):
    # (row, col, time)
    q = deque()
    # visited의 default 값을 (-1, -1)로 두었다.
    visited = [[[(-1, -1) for _ in range(m + 1)] for _ in range(n + 1)] for _ in range(target_t + 1)]

    q.append((start_r, start_c, 0))
    visited[0][start_r][start_c] = (0, 0)

    is_possible = False
    while q:
        curr_r, curr_c, curr_t = q.popleft()

        # k (= target_t) 번 이동해서 r(= target_r), c(= target_c)에 도달하였는가?
        if curr_t == target_t and (target_r == curr_r and target_c == curr_c):
            is_possible = True
            break

        # 목표보다 더 많이 움직이면 의미가 없다.
        next_t = curr_t + 1
        if next_t > target_t:
            continue

        for dr, dc in MOVES:
            next_r, next_c = curr_r + dr, curr_c + dc
            if (0 < next_r <= n) and (0 < next_c <= m):
                # 한번도 방문한적 없다면
                if visited[next_t][next_r][next_c] == (-1, -1):
                    visited[next_t][next_r][next_c] = (curr_r, curr_c)
                    q.append((next_r, next_c, next_t))

    if is_possible:
        ans = []
        curr_t = target_t
        curr_r, curr_c = target_r, target_c
        while curr_t: # k가 0이면 시작점이니 0보다 클 때만 조사
            prev_r, prev_c = visited[curr_t][curr_r][curr_c]

            diff_r, diff_c = curr_r - prev_r, curr_c - prev_c
            for inst, move in zip(INSTS, MOVES):
                if (diff_r, diff_c) == move:
                    ans.append(inst)

            curr_r, curr_c = prev_r, prev_c
            curr_t -= 1

        # 역추적이기 때문에 ans에는 거꾸로 순서가 저장된다. 이를 다시 거꾸로 하여 문자열로 바꿔주었다.
        return ''.join(reversed(ans))

    else:
        return "impossible"
