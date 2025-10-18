length = 8

def getStr():
    return str(input())

def printStr(a):
    print(a)

def isRightChars(a):
    return ((len(a) <= length) and (a.count('0') + a.count('1') == len(a)))

def addZeros(a):
    return a + '0' * (length - len(a))

def conjuction(a, b):
    result = ""
    for i in range(length):
        if (a[i] == '1') & (b[i] == '1'):
            result += '1'
        else: result += '0'
    return result

a = getStr()
if not isRightChars(a): exit()
a = addZeros(a)
printStr(a)

b = getStr()
if not isRightChars(b): exit()
b = addZeros(b)
printStr(b)

result = conjuction(a, b)

print(result)