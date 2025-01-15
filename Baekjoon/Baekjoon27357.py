# Baekjoon27357.py
import sys
from math import floor, ceil

input = sys.stdin.readline

for _ in range(int(input())):
    n, x = map(int, input().split())

    prices = [float(input()) for _ in range(n)]
    total = sum(prices)

    ans = [-1, 0]
    for i in range(0, 10_001):
        tax = total * (i * 0.01)

        lower = total + floor(tax * 100) / 100
        upper = total + ceil(tax * 100) / 100

        if floor(lower) == x or floor(upper) == x:
            if ans[0] == -1:
                ans[0] = i
            ans[1] = i

    print(f"{ans[0]} {ans[1]}")

