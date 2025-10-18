class BitString:
    def __init__(self, a=None):
        self.length = 8

        if a:
            self.line = a
        else: self.line = ""

        if not self.isRightChars(): exit()

        self.addZeros()

    def clear(self):
        self.line = ""

    def input(self):
        self.clear()
        self.line = str(input())

        if not self.isRightChars(): exit()

        self.addZeros()

    def print(self):
        print(self.line)

    def addZeros(self):
        self.line += '0' * (self.length - len(self.line))

    def conjuction(self, a):
        result = ""
        for i in range(self.length):
            if (a.line[i] == '1') & (self.line[i] == '1'):
                result += '1'
            else: result += '0'
        return BitString(result)

    def isRightChars(self):
        return ((len(self.line) <= self.length) and (self.line.count('0') + self.line.count('1') == len(self.line)))