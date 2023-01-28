file = open('sol.cpp', 'r')
lines = file.readlines()

chars = 0
for line in lines:
    for ch in line:
        if ch != ' ' and ch != '\n' and ch != '\t' and ch != '\0':
            chars += 1

print(chars)
