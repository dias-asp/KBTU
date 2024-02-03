class Shape:
    area = 0
    def printArea(self):
        print(self.area)
class Rectangle(Shape):
    def __init__(self, a, b):
        self.side1 = a
        self.side2 = b
    def calcArea(self):
        self.area = self.side1 * self.side2

x = Rectangle(5, 10)
x.calcArea()
x.printArea()