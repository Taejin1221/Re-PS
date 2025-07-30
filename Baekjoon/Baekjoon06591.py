# Baekjoon06591.py
n, k = map(int, input().split())

while not (n == 0 and k == 0):
    min_k = min(k, n - k)

    son = 1
    for i in range(n, n - min_k, -1):
        son *= i

    mom = 1
    for i in range(1, min_k + 1):
        mom *= i

    print(son // mom)

    n, k = map(int, input().split())
