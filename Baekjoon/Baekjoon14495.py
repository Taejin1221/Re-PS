n = int(input())

f = [0] * 200
f[1] = f[2] = f[3] = 1
for i in range(4, n + 1):
    f[i] = f[i - 1] + f[i - 3]
print(f[n])
