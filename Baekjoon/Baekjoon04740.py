# Baekjoon04740.py
word = input()
while word != "***":
    for i in range(len(word) - 1, -1, -1):
        print(word[i], end='')
    print()

    word = input()
