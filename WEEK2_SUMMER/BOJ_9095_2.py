#using Top-down

T = int(input())


def solve(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    else: 
        if dp[n]:
            return dp[n]
        return solve(n-1) + solve(n-2) + solve(n-3)

for t in range(T):
    N = int(input())
    print(solve(N))
