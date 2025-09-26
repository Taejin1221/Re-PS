n = int(input())
ans = n * (n + 1) // 2
print(ans)
print(ans * ans)

ans = 0
for i in range(1, n + 1):
    ans += i ** 3
print(ans)
