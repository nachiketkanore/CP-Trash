class nachiket:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return str((self.x, self.y))

N = nachiket()

print(N)

n = 10

ans = 0

for i in range(n):
    for j in range(i):
        if i > j:
            ans += 1

print(ans)
