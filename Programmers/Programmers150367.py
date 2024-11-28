# Programmers150367.py
def can(num, has_root):
    n = len(num)
    if n == 0:
        return True

    root = n // 2
    left = num[:root]
    right = num[root + 1:]
    if has_root:
        if num[root] == "1":
            return can(left, True) & can(right, True)
        else:
            return can(left, False) & can(right, False)
    else:
        if num[root] == "1":
            return False
        else:
            return can(left, False) & can(right, False)

def solution(numbers):
    ans = []

    NODES = [1, 3, 7, 15, 31, 63]
    for number in numbers:
        bin_num = bin(number)[2:]
        n = len(bin_num)

        can_make = False
        for node in NODES:
            if n <= node:
                if can('0' * (node - n) + bin_num, True):
                    can_make = True
                    break

        ans.append(1 if can_make else 0)

    return ans

print(solution([7, 42, 5]))