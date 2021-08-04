def power(base, exp, chk):
    """ Fast power calculation using repeated squaring """
    if exp < 0:
        return 1 / power(base, -exp)
    ans = 1
    while exp:
        if exp & 1:
            ans *= base
        exp >>= 1
        base *= base
        if ans >= chk:
        	return P
    return ans

for tc in range(int(input())):
	N, R, P = map(int, input().split())

	ans = -1
	lo = 0
	hi = 10**20

	while lo <= hi:
		mid = (lo + hi) // 2
		val = N * (power(1 + R / 100, mid, P))
		if val >= P:
			ans = mid
			hi = mid - 1
		else:
			lo = mid + 1
	assert(~ans)
	print('Case', tc+1, end = '')
	print(':', ans)
