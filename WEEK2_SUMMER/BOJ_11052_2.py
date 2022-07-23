# Card Max Costs
import sys
sys.setrecursionlimit(10**6)

N = int(input())
P = list(map(int , input().split(' ')))
dp = [[-1 for x in range(len(P))] for y in range(N+1)]

def solve(p, n, idx):
    if idx == len(P):
        return 0
    if n == 0:
        dp[n][idx] = 0
        return  0

    avail = n // (idx+1)
    max = 0
    for i in range(avail+1):
        if (idx + 1) != len(P) and dp[n-(idx+1) * (i)][idx+1] >= 0:
            r =p[idx] * i + dp[n-(idx+1) * i][idx+1] 
        else: 
            r = p[idx] * i + solve(p, n-(idx+1)*(i), idx+1)
        if r > max:
            max = r
    dp[n][idx] = max
    return max
    
print(solve(P, N, 0))
