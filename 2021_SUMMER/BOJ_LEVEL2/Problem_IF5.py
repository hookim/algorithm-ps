#2884 알람시계문제
h, m = input().split(' ')
h, m = int(h),int(m)
total = 60 * 24
h_in_m = 60 * h + m - 45
if h_in_m < 0:
    h_in_m += total
elif h_in_m >= total:
    h_in_m -= total
else:
    pass
print(h_in_m//60, h_in_m % 60)

