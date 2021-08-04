input()
a = ['','','2','3','322','5','53','7','7222','7332']
s = input()
vals = []
for dig in s:
	vals += a[int(dig)]
vals.sort()
print(''.join(vals[::-1]))