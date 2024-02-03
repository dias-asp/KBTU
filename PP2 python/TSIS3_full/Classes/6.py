ar = [i for i in range(1, 101)]

ar = filter(lambda a: sum([1 for i in range(1, a + 1) if a % i == 0]) == 2, ar)

print(*ar)