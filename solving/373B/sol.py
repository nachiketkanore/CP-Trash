have, start, k = map(int, input().split())

ans = 0
while have > 0:
	length = len(str(start))
	howMany = (10 ** length - start)
	cost = k * (howMany) * length
	if cost <= have:
		ans += howMany
		have -= cost
		start = 10 ** length
	else:
		ans += max(0, have // (k * length))
		have = 0

print(ans)