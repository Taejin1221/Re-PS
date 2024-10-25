# Baekjoon10173.py
line = input()
while line != "EOI":
    line = line.upper()
    if line.find("NEMO") == -1:
        print("Missing")
    else:
        print("Found")
    line = input()
