for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	s = int(input())
	found = False

	for mask in range(1, 1<<n):
		c = 0
		for i in range(n):
			if (mask >> i) & 1:
				c += a[i]
		found |= c == s

	print("YES" if found else "NO")