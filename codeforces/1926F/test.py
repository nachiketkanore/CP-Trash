import random as rand

tc = 5
print(tc)
for i in range(tc):
    for line in range(7):
        # mask = rand.randint((1 << 7) - 1, 1<<7)
        row = 'B' * 7
        # for j in range(7):
        #     if mask >> j & 1:
        #         row += 'B'
        #     else:
        #         row += 'W'
        print(row)
