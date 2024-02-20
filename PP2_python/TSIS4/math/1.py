import math

def convert(deg):
    return math.radians(deg)

degree = int(input("Input degree: "))
print(f'Output radian: {convert(degree)}')

