# least operation counts
n = int(input())

a = [-1] * (n+1)
a[1] = 0
for i in range(2, n+1):
    r1,r2,r3 = 10**6, 10 **6, 10 **6
    if i % 3 == 0:
        r1 = a[int(i/3)] + 1
    if i % 2 == 0:
        r2 = a[int(i/2)] + 1
    r3 = a[i-1] + 1
    a[i] = min(r1,r2,r3)
    
print(a[n])

