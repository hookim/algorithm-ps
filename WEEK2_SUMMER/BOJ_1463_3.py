# least operation counts
import sys
sys.setrecursionlimit(10**6)
n = int(input())

a = [-1] * (n+1)
a[1] = 0

def solve(i):
    r1, r2, r3 = 10 ** 6, 10 ** 6, 10 ** 6
    if i == 1:
        a[i] = 1
        return 1
    
    if a[i] > 0:
        return a[i]
    
    if i % 3 == 0 :
        r1 = solve(int(i / 3)) + 1
        
    if i % 2 ==0:
        r2 = solve(int(i / 2)) + 1
        
    if a[i-1] < 0:
        r3 = solve(i-1) + 1
    
    r =min(r1,r2,r3)
    a[i] = r

    return r

print(solve(n))