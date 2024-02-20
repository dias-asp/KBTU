import math


def calc_area(n, a):
    return n / 4 * a * a / math.tan(math.pi / n)

n = int(input("Input number of sides: "))
a = int(input("Input the length of a side: "))
print (f'The area of the polygon is: {calc_area(n, a)}')
