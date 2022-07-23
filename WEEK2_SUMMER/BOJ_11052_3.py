# Card Max Costs

N = int(input())
P = list(map(int , input().split(' ')))
dp = [0] * (N+1)

for i in range(1, N+1):
    max = 0
    for j in range(i):
        r = dp[j] + P[i-j-1]
        if max < r:
            max = r
    dp[i] = max

print(dp[N])