import math
A,B,C = input().split()
A,B,C = int(A),int(B),int(C)

if C <= B: print(-1)
else:
    x = A / (C - B)
    print(math.floor(x + 1))

