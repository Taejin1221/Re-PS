# Programmers77486.py
def solution(enroll, referral, sellers, amounts):
    match = { "center": 0 }

    num = 1
    for name in enroll:
        match[name] = num
        num += 1

    n = len(match)
    parent_list = [0 for _ in range(n + 1)]
    for idx, mom in enumerate(referral):
        if mom == "-":
            parent_list[idx + 1] = 0
        else:
            parent_list[idx + 1] = match[mom]

    ans = [0 for _ in range(n)]
    for seller, amount in zip(sellers, amounts):
        curr = match[seller]

        money = amount * 100
        while curr != 0 and money >= 10:
            ten = money // 10

            ans[curr] += money - ten

            money = ten
            curr = parent_list[curr]
        ans[curr] += money

    return ans[1:]