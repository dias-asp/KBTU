import math


def calc(a, b, h):
    return (a+b)/2*h

h = int(input("Height: "))
a = int(input("Base, first value: "))
b = int(input("Base, second value: "))
print (f'Expected Output: {calc(a, b, h)}')