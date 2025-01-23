# Baekjoon11319.py
VOWEL = "AEIOUaeiou"

for _ in range(int(input())):
    sentence = input()

    cons, vowel = 0, 0
    for s in sentence:
        if s == ' ':
            continue

        if s in VOWEL:
            vowel += 1
        else:
            cons += 1

    print(cons, vowel)
