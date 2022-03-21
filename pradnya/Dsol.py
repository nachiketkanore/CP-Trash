from math import *
from collections import *
import sys
from bisect import *
import io,os

MOD = 1000000007
sys.setrecursionlimit(10**6)

def subinp():
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("op1.txt", "w")


def sieve(n):
    if n < 9:
        n = 10
    l = [0]

    for i in range(1, n + 1):
        if i % 2:
            l.append(i)
        else:
            l.append(2)

    for i in range(3, int(n ** 0.5) + 1, 2):
        if l[i] == i:
            for j in range(i * i, n + 1, i):
                if l[j] == j:
                    l[j] = i
    return l


spf = sieve(10 ** 5 + 1)

def dfs(ajl, now, vis, l2, freq):
    l2.append(freq[now])
    vis[now] = True

    for i in ajl[now]:
        if not vis[i]:
            dfs(ajl, i, vis, l2, freq)

def getfact(x):
    ret = []
    while x != 1:
        ret.append(spf[x])
        x = x // spf[x]

    return set(ret)

def panda(n, l):
    d = defaultdict(bool)
    s1 = defaultdict(bool)
    freq = defaultdict(int)
    x = 0
    z = 0
    o = 0

    for i in l:
        freq[i] += 1
        if not i:
            z += 1
        elif i == 1:
            o += 1
        elif not s1[i]:
            l1 = getfact(i)
            for j in l1:
                if not d[j]:
                    d[j] = i
                    ajl[j].append(i)
                else:
                    ajl[d[j]].append(i)
                    ajl[i].append(d[j])
        s1[i] = True

    vis = defaultdict(bool)
    mx = 0
    for i in l:
        l2 = []
        if not vis[i]:
            dfs(ajl, i, vis, l2, freq)
        mx = max(sum(l2), mx)

    return min(n - o, n - (mx + z), n - 1)


input = sys.stdin.readline
t = 1
t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    ajl = defaultdict(list)
    print(panda(n, l))
