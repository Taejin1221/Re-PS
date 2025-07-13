# Baekjoon09093.py
for _ in range(int(input())):
    words = input().split()

    for word in words:
        print(word[::-1], end = ' ')
    print('')