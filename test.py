from sympy import mod_inverse
from random import randint

MOD = 10 ** 9 + 7

for _ in range(100000000):
    x = randint(2, 100)
    ans1 = pow(x, MOD - 2, MOD)
    ans2 = mod_inverse(x, MOD)

    assert(ans1 == ans2)
    print(f"OK {_ + 1}")
