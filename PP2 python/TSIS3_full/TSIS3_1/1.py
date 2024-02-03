#1
def convert_ounces(g):
    return g * 28.3495231

print(convert_ounces(100))

#2
def convert_celsius(F):
    return 5 / 9 * (F - 32)

print(convert_celsius(69))

#3
def solve(numheads, numlegs):
    y = (numlegs - 2 * numheads) / 2
    x = numheads - y
    return (int(x), int(y))

print(f'there are {solve(35, 94)[0]} rabbits and {solve(35, 94)[1]} chickens')
'''
#4
def filter_prime(a):
    return [num for num in a if sum([1 for i in range(1, num + 1) if num % i == 0]) == 2]

arr = list(map(int, input().split()))
arr = filter_prime(arr)
print (*arr)
'
#5
from itertools import permutations
s = input()
s1 = [''.join(p) for p in permutations(s)]
print(*s1, sep = ', ')

#6
s = input()
words = list(map(str, s.split()))
words.reverse()
print(*words)
'''
#7
def has_33(nums):
    for i in range(1, len(nums)):
        if nums[i] == nums[i - 1] == 3:
            return True
    return False

print(has_33([1, 3, 3]))
print(has_33([1, 3, 1, 3]))
print(has_33([3, 1, 3]))

#8
def spy_game(nums):
    i = 0
    if 0 not in nums[i:]:
        return False
    i = nums.index(0)
    nums.pop(i)
    if 0 not in nums[i:]:
        return False
    i = nums.index(0)
    if 7 not in nums[i:]:
        return False
    return True

print(spy_game([1,2,4,0,0,7,5]))
print(spy_game([1,0,2,4,0,5,7]))
print(spy_game([1,7,2,0,4,5,0]))

from math import pi
#9
def calc(r):
    return pi * r**3 * 4/3

print(calc(1))

#10
def unique(a):
    b = []
    for x in a:
        if x not in b:
            b.append(x)
    return b

print(*unique([1, 1, 2, 2, 2, 4, 3, 4, 3, 1, 5, 10]))
'''
#11
def ch(s):
    s1 = s[::-1]
    return (s == s1)

print(ch(input()))
'''
#12
def histogram(a):
    for x in a:
        print('*' * x, end = ' ')

histogram([4, 9, 7])

#13
import random
x = random.randint(1, 20)
name = input("Hello!\nWhat is you name?\n")
print(f'Well, {name}, I am thinking of a number between 1 and 20.')
cnt = 0
while True:
    y = int(input("Take a guess.\n"))
    cnt += 1
    if y < x:
        print("Your guess is too low.")
    if y > x:
        print("Your guess is too high.")
    if y == x:
        print(f'Good job, {name}!\nYou guessed my number in {cnt} guesses!')
        break

#14
