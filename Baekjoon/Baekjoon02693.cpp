import sys
input = sys.stdin.readline

t = int(input())
while (t != 0):
    l = sorted(list(map(int, input().split())), reverse=True)
    print(l[2])
    t -= 1
