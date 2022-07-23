# RGB Boulevard
import sys
input = sys.stdin.readline
N = int(input())

costs = []
for n in range(N):
    costs.append(list(map(int, input().rstrip().split(' '))))
dp = [[1000 for x in range(3)] for y in range(N)]

for color in range(3):
    dp[0][color] = costs[0][color]

exclude = [(1,2),(0,2),(0,1)]
for house in range(1,N):
    for color in range(3):
        c1 = exclude[color][0]
        c2 = exclude[color][1]
        # dp[color][house] = dp[color][house-1] + min(costs[house][c1], costs[house][c2])
        dp[house][color] = min(dp[house-1][c1], dp[house-1][c2]) + costs[house][color] 

print(min(dp[N-1][0], dp[N-1][1], dp[N-1][2]))
        


