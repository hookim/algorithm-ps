# Triangle
import sys
input= sys.stdin.readline

N = int(input())

triangle= []
for n in range(N):
    triangle.append([-1] * N)
    row = list(map(int, input().rstrip().split(' ')))
    triangle[n][:len(row)] = row

dp = [[0] * N for y in range(N)]
dp[0][0] = triangle[0][0]

for i in range(1, N):
    for j in range(i+1):
        for k in range(-1,1):
            idx = j + k
            if idx >= 0 and idx < i+1:
                dp[i][j] = max(dp[i][j], dp[i-1][idx] + triangle[i][j])
print(max(dp[N-1]))