def solve():
    N, H = map(int, input().split())
    A = list(map(int, input().split()))

    SUM = sum(A)

    def check(k):
        D = 0
        for x in A:
            D += (x // k) * (x // k)
        if D == 0:
            return True
        # check: SUM / D >= H ?
        return SUM >= H * D

    lo, hi = 1, max(A)
    answer = -1
    while lo <= hi:
        mid = (lo + hi) // 2
        if check(mid):
            answer = mid
            hi = mid - 1
        else:
            lo = mid + 1

    print(answer)

T = int(input())
for _ in range(T):
    solve()
