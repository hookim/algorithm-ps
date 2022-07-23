def solve_knapsack(profits, weights, capacity):
  
    dp = [[-1 for x in range(len(profits))] for y in range(capacity+1)]

    def solve(p, w, c, idx):
        if idx == len(p):
            return 0
        
        if dp[c][idx] > 0:
            return dp[c][idx]
        r1 = 0
        if weights[idx] <= c:
            r1 = profits[idx] + solve(p, w, c-weights[idx], idx+1)
        r2 = solve(p, w, c, idx+1)
        
        result = max(r1,r2)
        dp[c][idx] =result
        
        return result

    
    return solve(profits, weights, capacity, 0)



def main():
  print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 7))
  print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 6))


main()