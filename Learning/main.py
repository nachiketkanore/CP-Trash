import torch
import matplotlib
import test
from math import sqrt

print(test.VAR)
print(test.test_func('A', 'B'))
print(test.hello_world('Nachiket'))
print(matplotlib._version)

class nachiket:
    def __init__(self, x: str, y: str):
        self.x = x
        self.y = y

    def __str__(self):
        return str((self.x, self.y))

    def how_are_you(self, x, y):
        return sqrt(x * x + y * y)

x = torch.Tensor([1, 2, 3, 4, 5])
x = x.sqrt()
print(x)
print(x)


for i, value in enumerate([(1, 1), (2, 2), (3, 3)]):
    print(i, value)

N = nachiket('nachiket', 'kanore')
K = nachiket('kanore', 'nachiket')
print(N, K)

print(N.how_are_you(10, 20))
