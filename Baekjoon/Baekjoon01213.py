# Baekjoon01213.py
name = input()
name = sorted(name) # 사전 순 정렬

n = len(name)

sorry = False # 회문 체크 flag
palindrome = [ ' ' for _ in range(n) ]
left, right, middle, i = 0, n - 1, n // 2, 0
while (i < n):
    if (i != n - 1 and name[i] == name[i + 1]):
        palindrome[left] = name[i]
        left += 1
        palindrome[right] = name[i]
        right -= 1
    else:
        # 처음 홀수개인 알파벳 만나면
        if (palindrome[middle] == ' '):
            palindrome[middle] = name[i]
            i -= 1
        else: # 다른 알파벳이 이미 홀수개인 경우
            sorry = True
            break
    i += 2

if (sorry):
    print("I'm Sorry Hansoo")
else:
    print(*palindrome, sep='')