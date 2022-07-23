def solve_knapsack(profits, weights, capacity):
  # TODO: Write your code here
  def solve(bag, p, w, c, idx):
    print(idx)
    if idx == len(p):
      return 0
    mymax = 0
    for i in range(idx, len(p)):
      cur_p = p[i]
      cur_w = w[i]
      c -= cur_w
      if c > 0:
        bag.append((cur_p, cur_w))
        result =solve(bag, p, w, c, i)
        if result > mymax:
          mymax =result 
        bag.pop()

      c+= cur_w
      result =solve(bag, p, w, c, i)
      if result > mymax:
        mymax = result 

    return mymax
  
  result = solve([], profits, weights, capacity, 0)
  
  return result 

def main():
  print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 7))
  print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 6))


main()