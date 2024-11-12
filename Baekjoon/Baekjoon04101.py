# Baekjoon04101.py
n, m = map(int, input().split())
while not (n == 0 and m == 0):
    if n > m:
        print("Yes")
    else:
        print("No")
    n, m = map(int, input().split())