# tomato again 2
from collections import deque
import sys

input = sys.stdin.readline

M,N = list(map(int, input().rstrip().split(' ')))
mat = []
q = deque()
dists = []

for n in range(N):
    mat.append(list(map(int, input().rstrip().split(' '))))
    dists.append([-2] * M)
    for m in range(M):
        if mat[n][m] == 1:
            q.append((n,m))
            dists[n][m] = 0
        elif mat[n][m] == -1:
            dists[n][m] = -1

moves = [(0,1),(1,0),(-1,0),(0,-1)]

while len(q) > 0:
    cur = q.popleft()

    for move in moves:
        adj = (cur[0] + move[0], cur[1] + move[1])
        dist = dists[cur[0]][cur[1]]

        if 0 <= adj[0] < N and 0 <= adj[1] < M and mat[adj[0]][adj[1]] == 0:
            if dists[adj[0]][adj[1]] == -2:
                dists[adj[0]][adj[1]] = dist + 1
                q.append(adj)
            
fail = False
ans = 0
for n in range(N):
    for m in range(M):
        if dists[n][m] == -2:
            fail= True
            break
        if ans < dists[n][m]:
            ans = dists[n][m]        
    if fail:
        break

if fail:
    print(-1)
else:
    print(ans)
 