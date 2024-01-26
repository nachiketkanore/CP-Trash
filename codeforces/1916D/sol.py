from collections import Counter

LIM = 250000

squares = [''.join(sorted(str(i * i))) for i in range(1, LIM)]
freq = dict(Counter(squares))

k, fmax = max(freq.items(), key = lambda k: k[1])
# print(fmax)

answers = [i * i for i in range(1, LIM) if ''.join(sorted(str(i * i))) == k]
assert(len(answers) == fmax)

for T in range(int(input())):
    N = int(input())
    print('\n'.join(str(x) for x in answers[:N]))

