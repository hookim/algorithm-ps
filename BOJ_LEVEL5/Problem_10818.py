N = int(input())
list = input().split(' ')
min_max = [int(list[0]),int(list[0])]
for i in range(N):
    if int(list[i]) > min_max[1]:
        min_max[1] = int(list[i])
    if int(list[i]) < min_max[0]:
        min_max[0] = int(list[i])

print(min_max[0],min_max[1])
