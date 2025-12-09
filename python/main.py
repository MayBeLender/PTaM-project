import copy
from bitString import BitString

a, b, result = BitString(), BitString(), BitString()

try:
    a.input()
    print(a)

    b.input()
    print(b)

    result = a.conjuction(b)

    print(result)
except NameError as e:
    print(e)