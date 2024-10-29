# Baekjoon20206.py
a, b, c = map(int, input().split())
x1, x2, y1, y2 = map(int, input().split())

left, right = min(x1, x2), max(x1, x2)
bottom, top = min(y1, y2), max(y1, y2)

if (b >= 0):
    if ((-a * left - c <= b * bottom and -a * right - c <= b * bottom) or (-a * left - c >= b * top and -a * right - c >= b * top)):
        print("Lucky")
    else:
        print("Poor")
else:
    if ((-a * left - c >= b * bottom and -a * right - c >= b * bottom) or (-a * left - c <= b * top and -a * right - c <= b * top)):
        print("Lucky")
    else:
        print("Poor")
