# Baekjoon09507.py
import sys
input = sys.stdin.readline

fib = [ 1, 1, 2, 4 ]
for _ in range(4, 68):
	fib.append(fib[-1] + fib[-2] + fib[-3] + fib[-4])

t = int(input())
for _ in range(t):
	print(fib[int(input())])