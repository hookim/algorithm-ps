#sub sum

N = int(input())
S = list(map(int,input().split(' ')))

dp = [0] * N
dp[0] = S[0]
for i in range(1, N):
    dp[i] = dp[i-1]
    sum = 0 
    for j in range(i,-1,-1):
        sum += S[j]
        dp[i] = max(dp[i], sum)
        
print(max(dp))

