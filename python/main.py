length = 8

a = str(input())
if (len(a) > length) or not('1' in a) or not('0' in a): exit()
a += '0' * (length - len(a))
print(a)

b = str(input())
if (len(b) > length) or not('1' in b) or not('0' in b): exit()
b += '0' * (length - len(b))
print(b)

result = ""
for i in range(length):
    if (a[i] == '1') & (b[i] == '1'):
        result += '1'
    else: result += '0'

print(result)