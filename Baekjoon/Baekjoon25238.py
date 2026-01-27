# Baekjoon25238.py
a, b = map(int, input().split())

ans = a - (a * b / 100)
print(0 if ans >= 100.0 else 1)
