class string:
    def __init__(self):
        self.s = ''

    def getString(self):
        self.s = input()
    
    def printString(self):
        print(self.s.upper())

S = string()
S.getString()
S.printString()