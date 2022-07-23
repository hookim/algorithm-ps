# maximum wine 

N = int(input())
W = []

for n in range(N):
    W.append(int(input()))

dp = [[-1] * N for y in range(2)]

dp[0][0] = W[0]
if N >= 2:
    dp[0][1] = W[1]
    dp[1][1] = W[0] + W[1] 

for i in range(2, N):
    if W[i-1] > 0:
        dp[0][i] = max(dp[0][i-2], dp[1][i-2]) + W[i]
    else:
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]) + W[i]
    
    if W[i] > 0: 
        dp[1][i] = dp[0][i-1] + W[i] 
    else:
        dp[1][i] = max(dp[0][i-1], dp[1][i-1]) + W[i]

print(max(max(dp[0]), max(dp[1])))