#10950
T = int(input())

for i in range(T):
    x,y = input().split(' ')
    x,y = int(x),int(y)
    print(x+y)

#8393
print(int((T+1)*T/2))