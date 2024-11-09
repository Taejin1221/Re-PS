# Programmers60059.py
import copy

def rotate(arr):
    n = len(arr)
    temp = copy.deepcopy(arr)
    for i in range(n):
        for j in range(n):
            arr[j][n - (i + 1)] = temp[i][j]

def solution(key, lock):
    n = len(lock)
    m = len(key)

    for _ in range(4):
        for start_i in range(-(m - 1), n + m):
            for start_j in range(-(m - 1), n + m):
                result = copy.deepcopy(lock)
                for i in range(m):
                    for j in range(m):
                        if (0 <= start_i + i < n) and (0 <= start_j + j < n):
                            result[start_i + i][start_j + j] += key[i][j]

                can_open = True
                for i in range(n):
                    for j in range(n):
                        if result[i][j] != 1:
                            can_open = False
                            break

                    if not can_open:
                        break

                if can_open:
                    return True

        rotate(key)

    return False
