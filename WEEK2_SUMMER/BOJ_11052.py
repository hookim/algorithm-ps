# Card Max Costs

N = int(input())
P = list(map(int , input().split(' ')))

def solve(p, n, idx):
    if idx == len(P) or n == 0:
        return 0
    avail = n // (idx+1)
    max = 0
    for i in range(avail+1):
        r = p[idx] * i + solve(p, n-(idx+1)*(i), idx+1)
        if r > max:
            max = r
    return max
    
print(solve(P, N, 0))
