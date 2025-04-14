m, n = map(int, input().split())
snack = list(map(int, input().split()))

def get_num(size):
    result = 0
    for s in snack:
        result += s // size

    return result

left, right = 0, 1_000_000_000
while left + 1 < right:
    mid = (left + right) // 2

    if get_num(mid) >= m:
        left = mid
    else:
        right = mid

print(left)
