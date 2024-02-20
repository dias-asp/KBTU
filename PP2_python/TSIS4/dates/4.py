import datetime

x = datetime.date.today()
day = datetime.timedelta(days = 3)
y = x + day

t = y - x

print(t.days*86400)
