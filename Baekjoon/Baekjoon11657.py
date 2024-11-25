# Baekjoon11657.py
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
edges = []
for _ in range(m):
    a, b, c = map(int, input().split())
    edges.append((a, b, c))

shortest = [0x3f3f3f3f] * (n + 1)
shortest[1] = 0
for _ in range(n):
    for s, e, c in edges:
        if shortest[s] != 0x3f3f3f3f and shortest[s] + c < shortest[e]:
            shortest[e] = shortest[s] + c

is_negative = False
for s, e, c in edges:
    if shortest[s] != 0x3f3f3f3f and shortest[s] + c < shortest[e]:
        is_negative = True
        break

if is_negative:
    print(-1)
else:
    for ans in shortest[2:]:
        print(ans if ans < 0x3f3f3f3f else -1)
