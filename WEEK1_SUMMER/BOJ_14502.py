# lab
from collections import deque
import sys

input = sys.stdin.readline

N, M = list(map(int, input().rstrip().split(' ')))
g = []

for n in range(N):
    g.append(list(map(int, input().rstrip().split(' '))))

moves = [(0,1), (1,0), (-1,0), (0,-1)]

for n in range(N):
    for m in range(M):
        if g[n][m] == 2:
            q = deque()
            q.append((n,m))
            
            g[n][m] = -1

            while len(q) > 0:
                cur = q.popleft()

                for move in moves:
                    adj = (cur[0] + move[0], cur[1] + move[1])
                    
                    if 0 <= adj[0] < N and 0 <= adj[1] < M:
                        if g[adj[0]][adj[1]]== 0 or g[adj[0]][adj[1]] == 2:
                            g[adj[0]][adj[1]] = -1
                            q.append(adj)

safe = 0
for n in range(N):
    for m in range(N):
        if g[n][m] == 0:
            safe += 1
print(safe)




