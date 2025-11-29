h1, m1 = map(int, input().split(":"))
h2, m2 = map(int, input().split(":"))
if (h2 > h1):
    print("YES")
elif (h2 == h1):
    if (m2 > m1):
        print("YES")
    else:
        print("NO")
else:
    print("NO")
