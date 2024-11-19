# Baekjoon15686.py
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
city = [list(map(int, input().split())) for _ in range(n)]

houses = []
chickens = []
for i in range(n):
    for j in range(n):
        if city[i][j] == 1:
            houses.append((i, j))
        elif city[i][j] == 2:
            chickens.append((i, j))

ans = 0x3f3f3f3f
def solve(idx: int, selected: list[int]):
    global ans
    if len(selected) == m:
        result = 0
        for h_row, h_col in houses:
            temp = 0x3f3f3f3f
            for ch_row, ch_col in selected:
                temp = min(temp, abs(ch_row - h_row) + abs(ch_col - h_col))
            result += temp
        ans = min(ans, result)

    if idx >= len(chickens):
        return

    solve(idx + 1, selected)
    selected.append(chickens[idx])
    solve(idx + 1, selected)
    selected.pop()

solve(0, [])

print(ans)
