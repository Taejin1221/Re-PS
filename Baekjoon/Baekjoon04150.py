n = int(input())

f1, f2 = 1, 1
for i in range(3, n + 1):
    f3 = f1 + f2
    f1 = f2
    f2 = f3

print(f2)
