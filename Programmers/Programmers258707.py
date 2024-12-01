# Programmers258707.py
def solution(coin, cards):
    n = len(cards)
    target = n + 1

    ans = 1
    idx = n // 3
    
    deleted = [False] * n
    while idx < n:
        idx += 2

        condition = [
            [(0, n // 3), (0, n // 3)],
            [(0, n // 3), (n // 3, idx)],
            [(n // 3, idx), (n // 3, idx)]
        ]

        minus_coin = 0
        selected = (-1, -1)
        for first, second in condition:
            if minus_coin > coin:
                break

            for i in range(first[0], first[1]):
                for j in range(second[0], second[1]):
                    if (i != j) and (not deleted[i] and not deleted[j]):
                        if cards[i] + cards[j] == target:
                            selected = (i, j)

            if selected[0] == -1 and selected[1] == -1:
                minus_coin += 1
            else:
                coin -= minus_coin
                deleted[selected[0]] = deleted[selected[1]] = True
                break

        if selected[0] == -1 and selected[1] == -1:
            break

        ans += 1

    return ans
