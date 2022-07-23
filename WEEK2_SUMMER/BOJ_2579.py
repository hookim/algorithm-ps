# Step up 

N = int(input())
steps = [0]
for n in range(N):
    steps.append(int(input()))
dp = [[-1] * 2 for y in range(N+1)]

dp[1][0] = steps[1]
if N >= 2:
    dp[2][0] = steps[2]
    dp[2][1] =  steps[1] + steps[2]

for n in range(3,N+1):
    dp[n][0] = max(dp[n-2][0], dp[n-2][1]) + steps[n]
    dp[n][1] = dp[n-1][0] + steps[n]

print(max(dp[N]))