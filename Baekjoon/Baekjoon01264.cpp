string = input()
while string != '#':
    vowel = 0
    for i in string:
        if i in "aeiouAEIOU":
            vowel += 1

    print(vowel)
    string = input()
