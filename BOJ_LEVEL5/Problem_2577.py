A = int(input())
B = int(input())
C = int(input())
result = A * B * C
frq = [0] * 10
while True:
    frq[result % 10] += 1
    result //= 10
    if result == 0: break
for i in range(10):
    print(frq[i])
