# Baekjoon01865.py
import sys
input = sys.stdin.readline

INF = 1_000_000_007

def solve():
    n, m, w = map(int, input().split())

    edges = []
    for _ in range(m):
        s, e, t = tuple(map(int, input().split()))

        edges.append((s, e, t))
        edges.append((e, s, t))

    for _ in range(w):
        s, e, t = map(int, input().split())

        edges.append((s, e, -t))

    distance = [INF for _ in range(n + 1)]

    for _ in range(n - 1):
        for s, e, t in edges:
            distance[e] = min(distance[e], distance[s] + t)

    negative = False
    for s, e, t in edges:
        if distance[e] > distance[s] + t:
            negative = True
            break

    print("YES" if negative else "NO")


for _ in range(int(input())):
    solve()
