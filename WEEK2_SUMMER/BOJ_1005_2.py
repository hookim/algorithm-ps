# ACM Craft
import sys
input = sys.stdin.readline

T = int(input())

for t in range(T):
    N, K = list(map(int, input().rstrip().split(' ')))
    costs = list(map(int, input().rstrip().split(' ') ))
    adj_list = [[] for k in range(K)]
    for k in range(K):
        a,b = list(map(int, input().rstrip().split(' ')))
        adj_list[a-1]
    