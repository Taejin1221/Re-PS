# Baekjoon01929.py
n, m = map(int, input().split())

is_prime = [True] * (m + 2)

is_prime[0] = is_prime[1] = False
for i in range(2, m + 1):
    if is_prime[i]:
        if n <= i:
            print(i)

        for j in range(i * i, m + 1, i):
            is_prime[j] = False
