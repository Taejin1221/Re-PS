# Baekjoon02437.py
import sys
input = sys.stdin.readline

n = int(input())
arr = sorted(list(map(int, input().split())))

if arr[0] != 1:
    print(1)
else:
    result = arr[0]
    for a in arr[1:]:
        if result + 1 != a and result < a:
            break

        result += a

    print(result + 1)
