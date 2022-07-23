def solve_knapsack(profits, weights, capacity):
  
    dp = [[-1 for x in range(len(profits))] for y in range(capacity + 1)]
   
    for i in range(len(profits)):
        dp[0][i] = 0
    
    for c in range(1,capacity + 1):
        if weights[0] < capacity:
            dp[c][0] = profits[0]

    for c in range(1,capacity + 1):
        for i in range(1, len(profits)):
            r1 = 0
            if weights[i] <= c:
                r1 = profits[i] + dp[c-weights[i]][i-1]
            r2 = dp[c][i-1]
            dp[c][i] = max(r1, r2)
    
    return dp[capacity][len(profits) - 1]
            


def main():
  print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 7))
  print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 6))


main()