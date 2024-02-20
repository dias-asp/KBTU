def gen(n):
    for i in range(n, -1, -1):
        yield i

x = gen(int(input()))
for i in x:
    print(i)