def convert_ounces(g):
    return g * 28.3495231

def convert_celsius(F):
    return 5 / 9 * (F - 32)

def solve(numheads, numlegs):
    y = (numlegs - 2 * numheads) / 2
    x = numheads - y
    return (int(x), int(y))

def filter_prime(a):
    return [num for num in a if sum([1 for i in range(1, num + 1) if num % i == 0]) == 2]

from itertools import permutations
def perms(s):
    return [''.join(p) for p in permutations(s)]

def rev(s):
    words = list(map(str, s.split()))
    words.reverse()
    return words

def has_33(nums):
    for i in range(1, len(nums)):
        if nums[i] == nums[i - 1] == 3:
            return True
    return False

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

from math import pi
def calc_volume(r):
    return pi * r**3 * 4/3

def unique(a):
    b = []
    for x in a:
        if x not in b:
            b.append(x)
    return b

def ch_pal(s):
    s1 = s[::-1]
    return (s == s1)

def histogram(a):
    for x in a:
        print('*' * x, end = ' ')

def Game():
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
