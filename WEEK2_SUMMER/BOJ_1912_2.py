#sub sum

N = int(input())
S = list(map(int,input().split(' ')))

#if dp[k] means max subsum in range from 1 to k

dp = [0] * N 
dp[0] = S[0]
last_idx = 0
for i in range(1, N):
    dp[i] = dp[i-1]
    temp  = dp[i]
    sum = 0

    for j in range(i,last_idx , -1):
        sum += S[j]
        dp[i] = max(dp[i], sum)

    dp[i] = max(dp[i], dp[i-1] + sum)

    if temp != dp[i]:
        last_idx = i
print(dp[N-1])