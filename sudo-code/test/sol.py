T = int(input())
for tc in range(T):
    x, y = map(int, input().split())
    ans = (x * (x - 1) // 2) * y
    ans += (y * (y - 1) // 2) * x
    ans += x * y
    print(ans)
