# Programmers12951.py
def solution(s):
    n = len(s)

    ans = ''

    is_capital = True
    for i in range(n):
        temp = ''
        if s[i] == ' ':
            temp = ' '
            is_capital = True
        elif is_capital:
            temp = s[i].upper()
            is_capital = False
        else:
            temp = s[i].lower()

        ans += temp

    return ans
