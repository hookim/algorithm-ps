# ACM Craft

from collections import deque
import sys

input = sys.stdin.readline

T = int(input())

for t in range(T):
    N, K = list(map(int, input().rstrip().split(' ')))
    adj_l = []
    times = list(map(int, input().rstrip().split(' ')))
    for n in range(N):
        adj_l.append([])

    for k in range(K):
        a,b = list(map(int, input().rstrip().split(' ')))
        adj_l[b-1].append(a)
    
    dest = int(input())
    min_time = 100000

    q = deque()
    q.append((dest, times[dest-1]))
    ans = 0
    while len(q) > 0:
        cur, btime = q.popleft()

        for next in range(len(adj_l[cur-1])):
            adj = adj_l[cur-1][next]
            numOfNextBuildings = len(adj_l[adj-1])

            if numOfNextBuildings == 0:
                if btime+times[adj-1] > ans:
                    ans = btime+times[adj-1]
            
            else:
                q.append((adj, btime + times[adj-1]))
    
    print(ans)