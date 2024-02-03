class Shape:
    area = 0
    def printArea(self):
        print(self.area)
class Rectangle(Shape):
    def __init__(self, length, width):
        self.length = length
        self.width = width
    def calcArea(self):
        self.area = self.length * self.width

x = Rectangle(5, 10)
x.calcArea()
x.printArea()