#2588 입력되는 형태를 잘 볼 것
a = int(input())
b = int(input())
x = (b%100%10)*a
y = (b%100//10)*a
z = (b//100)*a

print(x)
print(y)
print(z)
print(x+10*y+100*z)