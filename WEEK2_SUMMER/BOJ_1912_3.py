#sub sum

N = int(input())
S = list(map(int,input().split(' ')))
#if dp[k] means max subsum that includes k
dp = [0] * N
dp[0] = S[0]
for i in range(1, N):
    dp[i] = max(dp[i-1] + S[i], S[i])
    
print(max(dp))