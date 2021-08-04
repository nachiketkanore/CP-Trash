n = int(input())
s = []
for _ in range(n):
	s.append(input())
yes = [False for _ in range(n)]

for i in range(n):
	for j in range(i+1,n):
		if s[i] in s[j]:
			yes[j] = True
		if s[j] in s[i]:
			yes[i] = True

print(sum(yes))