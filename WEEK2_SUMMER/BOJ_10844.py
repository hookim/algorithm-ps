#easy version : Step number

N = int(input())
dp = [[0] * 12 for y in range(N)]
for x in range(1, 10):
    dp[0][x] = 1
dp[0][10] = 9
dp[0][11] = 9

for x in range(1, N):
    sum = 0
    for y in range(1,9):
        dp[x][y] = dp[x-1][y-1] + dp[x-1][y+1]
        sum += dp[x][y]
    
    dp[x][0] = dp[x-1][1]
    dp[x][9] = dp[x-1][8]
    
    dp[x][10] = (sum + dp[x][0] + dp[x][9])
    dp[x][11] = dp[x-1][10]* 2 - dp[x-1][9] - dp[x-1][0]

print(dp)
print(dp[N-1][11] % (10**9))
    
