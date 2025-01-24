import heapq
for _ in range(int(input())):
    N, K = map(int, input().split())
    A = [int(a) for a in input().split()]
    B = [int(b) for b in input().split()]
    C = [(a, b) for a, b in zip(A, B)]
    C.sort()
    ans = 10**18
    b_values = []
    heapq.heapify(b_values)
    smallest_sum = 0
    for idx, (a, b) in enumerate(C):
        if idx >= K - 1:
            ans = min(ans, a * (smallest_sum + b))
        heapq.heappush(b_values, -b)
        smallest_sum += b
        while len(b_values) > K - 1:
            removed = -heapq.heappop(b_values)
            smallest_sum -= removed
    print(ans)
