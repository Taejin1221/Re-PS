n = int(input())

pattern = {}
for _ in range(n):
    v, k = input().split()
    pattern[k] = v

comp = input()
ans = ""
for c in comp:
    ans += pattern[c]

s, e = map(int, input().split())
print(ans[s - 1:e])
