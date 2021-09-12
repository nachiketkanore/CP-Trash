from datetime import datetime

date_1 = input()
date_2 = input()

date_format_str = '%Y-%m-%d %H:%M:%S'

start = datetime.strptime(date_1, date_format_str)
end =   datetime.strptime(date_2, date_format_str)
# get the difference between two dates as timedelta object

diff = end.date() - start.date()

# print(diff.hours)
# print(diff.minutes)
print(diff.seconds)

