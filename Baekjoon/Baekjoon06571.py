# Baekjoon06571.cpp
from bisect import bisect

fib = [1, 2]
for _ in range(1_000):
    fib.append(fib[-1] + fib[-2])

a, b = map(int, input().split())
while not (a == 0 and b == 0):
    a_num = bisect(fib, a - 1)
    b_num = bisect(fib, b)
    print(b_num - a_num)

    a, b = map(int, input().split())
