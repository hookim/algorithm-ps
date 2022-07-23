#increasing sub series

N = int(input())
S = list((map(int,input().split(' '))))

dp = [0] * N
dp[0] = 1

for i in range(1, N):   
    m = 1
    for j in range(0, i):
        r = 0
        if S[i] > S[j]:
            r = dp[j] + 1
        if r > m:
            m = r
    dp[i] = m

print(max(dp))

