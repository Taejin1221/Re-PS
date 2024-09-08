# Baekjoon01009.py
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a, b = map(int, input().split())

    c = 1
    for _ in range(b):
        c *= a
        c %= 10

    print(c % 10 if c % 10 != 0 else 10)