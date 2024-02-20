import datetime

x = datetime.date.today()
t = datetime.timedelta(days = 1)

print(f'Yesterday: {x-t}')
print(f'Today: {x}')
print(f'Tomorrow: {x+t}')