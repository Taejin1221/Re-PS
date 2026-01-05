# Baekjoon04732.py
melody = ["A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"]
melody_idx = {
    "A": 0, "A#": 1, "B": 2, "C": 3, "C#": 4, "D": 5, "D#": 6, "E": 7, "F": 8, "F#": 9, "G": 10, "G#": 11,
    "Ab": 11, "Bb": 1, "Cb": 2, "Db": 4, "Eb": 6, "Fb": 7, "Gb": 9,
    "B#": 3, "E#": 8
}

t = input()
while (t != "***"):
    n = int(input())

    src = list(t.split())
    for s in src:
        idx = (melody_idx[s] + n + 12) % 12
        print(melody[idx], end = ' ')
    print()

    t = input()
