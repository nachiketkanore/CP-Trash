n = int(input())
ans = 0
for i in range(n):
    for j in range(i):
        for k in range(k):
            if a[i] < a[j] and a[j] > a[k]:
                ans += 1


for i in range(n):
    if a[i] % 20 == 0:
        print('answer found')

for _ in range(int(input())):
    n = input()
    for i in range(n):
        s = input()
        print(len(set(s)))


