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

    def conjuction(self, a):
        result = ""

        if self.length != a.length: raise ValueError("BitStrings must be equal sizes")

        for i in range(self.length):
            if (a.line[i] == '1') & (self.line[i] == '1'):
                result += '1'
            else: result += '0'
        return BitString(result)

    def isRightChars(self):
        return self.line.count('0') + self.line.count('1') == len(self.line)