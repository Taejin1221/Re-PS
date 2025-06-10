# Baekjoon01740.py
n = int(input())

binary = []
while n:
    binary.append(n % 2)
    n //= 2

ans = 0
for i, b in enumerate(binary):
    ans += (3 ** i) * b

print(ans)