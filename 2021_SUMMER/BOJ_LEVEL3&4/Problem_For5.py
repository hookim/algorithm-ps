#10871
N,x = input().split(' ')
N,x = int(N),int(x)
list = input().split(' ')
for i in range(N):
    if x > int(list[i]): print(list[i], end = " ")

