# Baekjoon30924.py
from random import shuffle
import sys

input = sys.stdin.readline

candidate_A = [i for i in range(1, 10_001)]
candidate_B = [i for i in range(1, 10_001)]

shuffle(candidate_A)
shuffle(candidate_B)

for a in candidate_A:
    print(f'? A {a}', flush=True)

    response = int(input())
    if (response == 1):
        A = a
        break

for b in candidate_B:
    print(f'? B {b}', flush=True)

    response = int(input())
    if (response == 1):
        B = b
        break

print(f'! {A + B}')