# Programmers87946.py
def solution(k, dungeons):
    n = len(dungeons)

    ans = 0
    visited = [False] * len(dungeons)

    def solve(rest, explore):
        nonlocal ans
        ans = max(ans, explore)

        for i in range(n):
            if not visited[i]:
                if dungeons[i][0] <= rest:
                    visited[i] = True
                    solve(rest - dungeons[i][1], explore + 1)
                    visited[i] = False

    solve(k, 0)

    return ans
