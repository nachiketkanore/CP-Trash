inf = 10 **18

for i in range(int(input())):
	l, b, h, n = map(int, input().split())

	def good(L, B, H, C):
		cL = C // L;
		cB = C // B;
		cH = C // H;
		return cL * cB * cH >= n;

	def ok(c):
		return good(l, b, h, c) or good(l, h, b, c) or good(h, l, b, c) or good(h, b, l, c) or good(b, l, h, c) or good(b, h, l, c);

	lo = 1
	hi = inf
	ans = -1;
	while lo <= hi:
		mid = (lo + hi) // 2
		if ok(mid):
			ans = mid
			hi = mid-1
		else:
			lo = mid+1
	
	assert(~ans)
	print(ans)