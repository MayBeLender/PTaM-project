length = 8

a = str(input())
if ((len(a) > length) or (a.count('0') + a.count('1') != len(a))): exit()
a += '0' * (length - len(a))
print(a)

b = str(input())
if ((len(b) > length) or (b.count('0') + b.count('1') != len(b))): exit()
b += '0' * (length - len(b))
print(b)

result = ""
for i in range(length):
    if (a[i] == '1') & (b[i] == '1'):
        result += '1'
    else: result += '0'

print(result)