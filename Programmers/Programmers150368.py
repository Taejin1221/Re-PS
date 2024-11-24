# Programmers150368.py
def solution(users, emoticons):
    n = len(users)
    m = len(emoticons)

    ans = []
    curr_discount = []
    def solve(idx):
        if idx == m:
            result = [0, 0]
            # 사용자가 원하는 할인율, 이모티콘 플러스를 결제하는 기준
            for want_discount, threshold in users:
                sum_of_buy = 0
                # 이모티콘의 가격, 지정한 할인율
                for price, discount in zip(emoticons, curr_discount):
                    if want_discount <= discount:
                        discount_price = price // 100 * discount
                        sum_of_buy += price - discount_price
                        # sum_of_buy += price // 100 * (100 - discount)

                if sum_of_buy >= threshold:
                    result[0] += 1
                else:
                    result[1] += sum_of_buy
            ans.append(result)
        else:
            for discount in [10, 20, 30, 40]:
                curr_discount.append(discount)
                solve(idx + 1)
                curr_discount.pop()

    solve(0)

    return sorted(ans, reverse=True)[0]
