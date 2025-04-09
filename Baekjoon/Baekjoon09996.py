# Baekjoon09996.py
import sys
input = sys.stdin.readline
t = int(input())

pattern = input().rstrip()
prefix, postfix = pattern.split('*')

n, m = len(prefix), len(postfix)

for _ in range(t):
    name = input().rstrip()
    if n + m > len(name):
        print("NE")
    else:
        if name[:n] == prefix and name[-m:] == postfix:
            print("DA")
        else:
            print("NE")
