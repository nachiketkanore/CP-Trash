import sys
from functools import cache
sys.setrecursionlimit(10**9)

S = input()
Q = [input() for _ in range(int(input()))]

INF = 10**9

@cache
def best(l, r):
    check = INF
    match = S[l:r+1]
    for q in Q:
        if len(q) == len(match) and sorted(match) == sorted(q):
            check = min(check, sum(a != b for a, b in zip(match, q)))
    return check

@cache
def go(from_id):
    if from_id >= len(S):
        return 0
    ans = INF
    for j in range(from_id, len(S)):
        choice = best(from_id, j)
        if choice < INF:
            ans = min(ans, choice + go(j + 1))
    return ans

ans = go(0)
print(ans if ans < INF else -1)

