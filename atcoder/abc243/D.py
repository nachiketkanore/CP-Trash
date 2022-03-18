N, X = map(int, input().split())
S = input()

for ch in S:
    if ch == 'L':
        X <<= 1
    elif ch == 'R':
        X <<= 1
        X += 1
    else:
        X >>= 1

print(X)
