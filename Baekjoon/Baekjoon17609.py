# Baekjoon17609.py
import sys
input = sys.stdin.readline

def is_palindrome(s, left, right):
    while (left < right):
        if (s[left] != s[right]):
            return False
        left += 1
        right -= 1
    return True

for _ in range(int(input())):
    s = input().rstrip()

    ans = 0
    left, right = 0, len(s) - 1
    while (left < right):
        if (s[left] != s[right]):
            if (is_palindrome(s, left + 1, right) or is_palindrome(s, left, right - 1)):
                ans = 1
                break
            else:
                ans = 2
                break
        left += 1
        right -= 1

    print(ans)
