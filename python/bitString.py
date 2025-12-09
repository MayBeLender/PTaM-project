class BitString:
    def __init__(self, a=None):
        self.length = 8

        if a:
            self.line = a
            self.length = len(a)
        else: self.line = ""

        if not self.isRightChars(): raise TypeError("Symbols must be '0' or '1'")

        self.addZeros()

    def __copy__(self):
        return BitString(self.line)

    def __del__(self):
        del self.line
        del self.length

    def __str__(self):
        return self.line

    def clear(self):
        self.line = ""

    def input(self):
        self.clear()
        self.line = str(input())
        self.length = len(self.line)

        if not self.isRightChars(): raise TypeError("Symbols must be '0' or '1'")

        self.addZeros()

    def addZeros(self):
        self.line += '0' * (self.length - len(self.line))

    def isRightChars(self):
        return self.line.count('0') + self.line.count('1') == len(self.line)

#=, <<, >>, &, []
#Перегрузка операций
    def assign(self, new_line):
        if len(new_line) < 1: raise ValueError("Assigning value len must be greater than 0")
        self.line = str(input())
        self.length = len(self.line)

    def __lshift__(self, i):
        if (i < 0): return(self >> -i)
        if (i >= self.length): return BitString('0' * self.length)
        
        result = ""
        for index in range(i, self.length):
            result += self[index]
        
        return BitString(result + '0' * i)

    def __rshift__(self, i):
        if (i < 0): return(self << -i)
        if (i >= self.length): return BitString('0' * self.length)

        result = ""
        for index in range(0, self.length - i):
            result += self[index]
        
        return BitString('0' * i + result)

    def __and__(self, a):
        result = ""

        if self.length != a.length: raise ValueError("BitStrings must be equal sizes")

        for i in range(self.length):
            if (a.line[i] == '1') & (self.line[i] == '1'):
                result += '1'
            else: result += '0'
        return BitString(result)

    def __getitem__(self, i):
        if i > self.length - 1: raise KeyError("Index out of range")
        return self.line[i]
