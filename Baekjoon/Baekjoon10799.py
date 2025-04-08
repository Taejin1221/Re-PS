# Baekjoon10799.py
brackets = input()

n = len(brackets)

ans, stck = 0, 0

i = 0
while i < n:
    if brackets[i] == '(':
        if i + 1 < n and brackets[i + 1] == ')':
            ans += stck
            i += 1
        else:
            stck += 1
    else:
        ans += 1
        stck -= 1

    i += 1

print(ans)
