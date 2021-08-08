#1330
x,y = input().split(' ')
x,y = int(x),int(y)

if x > y:
    print(">")
elif x < y:
    print("<")
else:
    print("==")