r, c, n = map(int, input().split())
a = r // n + (0 if r % n == 0 else 1)
b = c // n + (0 if c % n == 0 else 1)
print(a * b)
