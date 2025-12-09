import copy
from bitString import BitString

a, b, result = BitString(), BitString(), BitString()

a.input()
a.print()

b = copy.copy(a)
#b.input()
b.print()

result = a.conjuction(b)

result.print()