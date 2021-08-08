import sys
#15552 빠르게 입력받는 법
# T = int(input())
# for i in range(T):
#     x,y = sys.stdin.readline().strip().split(' ')
#     print(int(x)+int(y))

#2741
# for i in range(T):
#     print(i+1)

#2742
# for i in range(T,0,-1):
#     print(i)

#11021
# for i in range(T):
#     x,y = sys.stdin.readline().split(' ')
#     x,y = int(x), int(y)
#     print("Case #%d : %d"%(i+1, x+y))

# 11022
for i in range(T):
    x,y = sys.stdin.readline().split(' ')
    x,y = int(x), int(y)
    print("Case #%d: %d + %d = %d"%(i+1,x,y, x+y))
