# Baekjoon09656.py
n = int(input())

is_win = [ True, False, True, False ]
for i in range(4, n + 1):
	is_win.append(False if (is_win[i - 1] and is_win[i - 3]) else True)

print("SK" if is_win[n] else "CY")