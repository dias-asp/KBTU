import datetime

x = datetime.datetime.today()
t = datetime.timedelta(microseconds=x.microsecond)
x -= t

print(x)