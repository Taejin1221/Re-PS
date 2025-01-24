_ = input()
string = input()

num_e = string.count('e')
num_2 = string.count('2')
if num_2 > num_e:
    print('2')
elif num_2 < num_e:
    print('e')
else:
    print("yee")
