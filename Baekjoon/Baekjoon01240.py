# Baekjoon01240.py
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

adjList = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v, d = map(int, input().split())

    adjList[u].append((v, d))
    adjList[v].append((u, d))

def getDistance(me, mom, target):
    if (me == target):
        return 0
    else:
        for son, dis in adjList[me]:
            if (son != mom):
                result = getDistance(son, me, target)
                if (result != -1):
                    return result + dis

    return -1

for _ in range(m):
    u, v = map(int, input().split())
    print(getDistance(u, 0, v))