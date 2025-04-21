# Programmers72410.py
def solution(new_id):
    # step 1
    new_id = new_id.lower() 

    new_char = []
    for c in new_id:
        # step 2
        if c in 'abcdefghijklmnopqrstuvwxyz0123456789-_': 
            new_char.append(c)
        # step 3
        elif c == '.':
            if len(new_char) == 0 or new_char[-1] != '.': 
                new_char.append(c)

    # step 4
    n = len(new_char)

    i = 0
    while i < n and new_char[i] == '.':
        i += 1

    j = n - 1
    while j >= 0 and new_char[j] == '.':
        j -= 1

    new_char = new_char[i:j + 1] 

    # step 5
    if len(new_char) == 0: 
        new_char = ['a']

    # step 6
    if len(new_char) > 15: 
        new_char = new_char[:15]

    n = len(new_char)
    j = n - 1
    while j >= 0 and new_char[j] == '.':
        j -= 1
    new_char = new_char[:j + 1] 

    # step 7
    while len(new_char) <= 2:
        new_char.append(new_char[-1])

    return ''.join(new_char)
