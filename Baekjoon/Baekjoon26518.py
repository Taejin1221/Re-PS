# Baekjoon26518.py
b, c, a1, a2 = map(int, input().split())

for i in range(5_000):
    curr = b * a2 + c * a1
    a1 = a2
    a2 = curr

print(f'{a2 / a1:.6f}')