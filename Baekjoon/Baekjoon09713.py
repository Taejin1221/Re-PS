# Baekjoon09713.py
for _ in range(int(input())):
    n = int(input())
    ans = 0
    for i in range(1, n + 1, 2):
        ans += i
    print(ans)
