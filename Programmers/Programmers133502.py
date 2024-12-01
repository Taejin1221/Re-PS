# Programmers133502.py
def solution(ingredient):
    ans = 0

    stck = []
    for ingre in ingredient:
        stck.append(ingre)
        if len(stck) >= 4:
            if (
                stck[-1] == 1 and
                stck[-2] == 3 and
                stck[-3] == 2 and
                stck[-4] == 1
            ):
                for _ in range(4):
                    stck.pop()
                ans += 1

    return ans
