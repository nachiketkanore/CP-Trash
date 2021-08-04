import numpy as np

n = int(input())

ans = 0

for i in range(n):
    for j in range(i):
        if i > j:
            ans += 1

print(ans)
