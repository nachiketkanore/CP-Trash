input()
h25 = 0
h50 = 0
yes = True

for x in input().split():
	x = int(x)
	if x==25:
		h25 += 1
	elif x==50:
		if h25 > 0:
			h25 -= 1
			h50 += 1
		else:
			yes = False
	else:
		if h25 > 0 and h50 > 0:
			h25 -= 1
			h50 -= 1
			continue
		if h25 >= 3:
			h25 -= 3
			continue
		yes = False

print(yes)