# Baekjoon01783.py
n, m = map(int, input().split())


if n == 1:
    ans = 1
elif n == 2:
    if m < 3:
        ans = 1
    elif m < 5:
        ans = 2
    elif m < 7:
        ans = 3
    else:
        ans = 4
else:
    if m == 1:
        ans = 1
    elif m == 2:
        ans = 2
    elif m == 3:
        ans = 3
    elif m <= 6:
        ans = 4
    else:
        ans = 5 + (m - 7)

print(ans)
