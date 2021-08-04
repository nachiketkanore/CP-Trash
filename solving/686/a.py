input()
a = min(input().split())
b = min(input().split())
print(''.join(sorted(set(a) | set(b))))