import libraryfolder
from libraryfolder import library

print(library.convert_ounces(100))

print(library.convert_celsius(69))

print(f'there are {library.solve(35, 94)[0]} rabbits and {library.solve(35, 94)[1]} chickens')

arr = list(map(int, input().split()))
arr = library.filter_prime(arr)
print (*arr)

s = input()
s1 = library.perms(s)
print(*s1, sep = ', ')

s = input()
print(*library.rev(s))

print(library.has_33([1, 3, 3]))
print(library.has_33([1, 3, 1, 3]))
print(library.has_33([3, 1, 3]))

print(library.spy_game(list(map(int, input().split()))))
print(library.spy_game([1,2,4,0,0,7,5]))
print(library.spy_game([1,0,2,4,0,5,7]))
print(library.spy_game([1,7,2,0,4,5,0]))

print(library.calc_volume(1))

print(*library.unique([1, 1, 2, 2, 2, 4, 3, 4, 3, 1, 5, 10]))

print(library.ch_pal(input()))

library.histogram([4, 9, 7])

library.Game()