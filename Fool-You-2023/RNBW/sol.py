T = int(input())
for _ in range(T):
    s = set(sorted(input()))
    print("yes" if len(s) == 7 else "no")
