import sys
T = int(input())
for _ in range(T):
    N, M = list(map(int, sys.stdin.readline().split()))
    print(((pow(10, N, 9 * M) - 1) % (9 * M) // 9))
