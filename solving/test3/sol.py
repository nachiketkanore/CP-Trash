n = int(input())
x, y = map(int, input().split())
a = [0] * n
b = [0] * n

for i in range(n):
	vals = map(int, input().split())
	a[i] = vals[0]
	b[i] = vals[1]

print(a)
print(b)

dp = [[0 for x in range(3000)] for y in range(3000)] 
inf = 10**18

def go(id, one, two):
	if one > x or two > y:
		return inf
	if id == n:
		return 0
	if ~dp[id][one]:
		return dp[id][one]
	ans = inf
	ans = min(ans, a[id] + go(id+1, one+1, two))
	ans = min(ans, b[id] + go(id+1, one, two+1))
	dp[id][one] = ans
	return ans

print(go(0, 0, 0))