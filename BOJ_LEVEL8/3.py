#1193
N = int(input())

dig = 1
last_fountain = 1
distance = 1
while True:
    if last_fountain >= N: break
    distance += 1
    last_fountain += distance
    dig += 1

first_fountain = last_fountain - dig + 1

if dig == 1 : print("1/1")
elif dig % 2 == 0 : 
    top = (N - first_fountain + 1)
    down = dig + 1 -top
    print("%d/%d"%(top,down))
else:
    down = (N - first_fountain + 1)
    top = dig + 1 -down
    print("%d/%d"%(top,down))