n, k = map(int, input().split())
print(sum([1 if set(input()) >= set('0123456789'[:k+1]) else 0 for x in range(n)]))