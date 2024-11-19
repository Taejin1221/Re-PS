# Baekjoon02075.py
import sys
input = sys.stdin.readline

n = int(input())
mat = [list(map(int, input().split())) for _ in range(n)]

indexes = [n - 1] * n

def get_biggest_index():
    s_col = 0 # biggest_column
    for i in range(n):
        if indexes[i] >= n:
            continue

        if s_col >= 0:
            if mat[indexes[s_col]][s_col] < mat[indexes[i]][i]:
                s_col = i
        elif s_col < 0:
            s_col = i

    return s_col

for _ in range(n - 1):
    indexes[get_biggest_index()] -= 1    

ans = get_biggest_index()
print(mat[indexes[ans]][ans])
