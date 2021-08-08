#10950
# while True:
#     x,y = input().split(' ')
#     x,y = int(x),int(y)
#     if(not (x or y)): break
#     print(x+y)

#10951
# import sys
# while True:
#     str = sys.stdin.readline().rstrip()
#     if(str == ""): break
#     x,y = str.split(' ')
#     x,y = int(x),int(y)
#     print(x+y)

n = int(input())
count =1
x,y = n//10, n % 10
z = x+y
new_number = 10*y + z%10
while True:
    if (new_number == n): break
    count += 1
    x,y = new_number // 10, new_number % 10
    z = x + y
    new_number = 10*y + z % 10
print(count)