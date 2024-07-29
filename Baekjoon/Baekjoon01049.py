# Baekjoon01049.py
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

# set6: 6세트 가격, one: 1개당 가격
set6, one = [], []
for i in range(m):
    a, b = map(int, input().split())
    set6.append(a), one.append(b)

# 각각 가장 싼 가격 선택
minSet, minOne = min(set6), min(one)

ans = 0
# 6개 낱개를 사는 것보다 6개 세트로 사는 것이 싼 경우
if (minSet < minOne * 6):
    # 6개 세트로 전부 구매
    ans += n // 6 * minSet; n %= 6

    # 남은 개수를 낱개로 사는 것 보다 6개 세트로 사는 것이 싼 경우
    if (minSet <= minOne * n):
        ans += minSet
    else:
        ans += minOne * n
else:
    ans = minOne * n

print(ans)