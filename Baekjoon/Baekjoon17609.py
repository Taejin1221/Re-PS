# Baekjoon17609.py
# '24. 8. 12. 풀이
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

# '24. 11. 29. 풀이
import sys
sys.setrecursionlimit(100_000)

def solve(string: str, left: int, right: int, is_deleted: bool) -> int:
    if left >= right:
        return 1 if is_deleted else 0
    else:
        if string[left] == string[right]:
            return solve(string, left + 1, right - 1, is_deleted)
        else:
            if not is_deleted:
                return min(
                    solve(string, left + 1, right, True),
                    solve(string, left, right - 1, True)
                )
            else:
                return 2

n = int(input())
for _ in range(n):
    str1 = input()
    print(solve(str1, 0, len(str1) - 1, False))
