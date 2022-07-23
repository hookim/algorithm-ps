# calculate Earth, Sun, Moon calendar
E, S, M = list(map(int, input().split(' ')))

cur = [1,1,1]
count = 1
while cur[0] != E or cur[1] != S or cur[2] != M:
    count += 1
    cur[0] = cur[0] % 15 + 1
    cur[1] = cur[1] % 28 + 1
    cur[2] = cur[2] % 19 + 1

print(count)