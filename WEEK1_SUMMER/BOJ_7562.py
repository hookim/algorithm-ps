#Knight moves

import sys
from collections import deque

input = sys.stdin.readline
moves = [(-1,2),(-2,1), (1,2), (2,1), (-2,-1), (-1,-2), (2,-1), (1,-2)]
T = int(input())
for t in range(T):
    N = int(input())
    src = tuple(map(int, input().split(' ')))
    dest = tuple(map(int, input().split(' ')))
    
    visited = []
    
    for n in range(N):
        visited.append([0] * N)
    
    queue = deque()
    queue.append(src) 
    dist_queue = deque()
    dist_queue.append(0)
    ans = 0
    
    visited[src[0]][src[1]] = 1

    while len(queue) > 0:
        cur = queue.popleft()
        dist = dist_queue.popleft()

        if cur[0] == dest[0] and cur[1] == dest[1]:
            ans = dist
            break  

        for move in moves:
            adj = (cur[0] + move[0], cur[1] + move[1])
            
            if 0 <= adj[0] < N and  0 <= adj[1] < N:
                if not visited[adj[0]][adj[1]] and adj:
                    visited[adj[0]][adj[1]] = 1
                    queue.append(adj) 
                    dist_queue.append(dist + 1)
    print (ans)