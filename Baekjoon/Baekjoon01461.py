# Baekjoon01461.py
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

# 양수, 음수 분리
pos, neg = [], []
for temp in map(int, input().split()):
    if temp > 0:
        pos.append(temp)
    else:
        neg.append(-temp)
pos.sort()
neg.sort()

# 책의 위치가 더 멀리 있는 배열을 arr[0]으로
# 배열이 비어있을 때 -1로 접근하면 Index Error가 발생하기 때문에 비어있는 경우를 체크한다.
if len(neg) == 0:
    arr = [pos, neg]
elif len(pos) == 0:
    arr = [neg, pos]
else:
    arr = [pos, neg] if pos[-1] > neg[-1] else [neg, pos]

# 가장 멀리 있는 책은 편도 간다.
ans = arr[0][-1]

# 가장 멀리 있는 책을 가져다 놓으며 같이 놓을 수 있는 다른 책도 같이 놓는다.
i = 0
while i < m and arr[0]:
    arr[0].pop()
    i += 1

for a in arr:
    # 더 놓을 책이 있으면
    while a:
        # 왕복으로 다녀온 뒤
        ans += a[-1] * 2

        # 같이 놓을 수 있는 다른 책도 같이 놓는다.
        i = 0
        while i < m and a:
            a.pop()
            i += 1

print(ans)
