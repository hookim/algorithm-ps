# tomato again
from collections import deque
import sys

input = sys.stdin.readline

M,N = list(map(int, input().rstrip().split(' ')))
mat = []
for n in range(N):
    mat.append(list(map(int, input().rstrip().split(' '))))

moves = [(0,1),(1,0),(-1,0),(0,-1)]
ans = 0
cnt = 0
any_ripen = False
fail = False

for n in range(N):
    for m in range(M):

        if mat[n][m] != -1 and mat[n][m] != 1: 
            found = False   
            cnt += 1
            q = deque()
            q.append((n,m,0))

            mat[n][m] = cnt + 1

            while len(q) > 0 :

                cur = q.popleft()
                dist = cur[2]

                for move in moves:
                    adj = (cur[0] + move[0], cur[1] + move[1], dist+1)
                    if 0 <= adj[0] < N and 0 <= adj[1] < M and mat[adj[0]][adj[1]] != -1 and mat[adj[0]][adj[1]] != cnt + 1:
                        if mat[adj[0]][adj[1]] == 1:
                            found = True
                            if ans < dist + 1:
                                ans = dist + 1
                            break
                        
                        mat[adj[0]][adj[1]] = cnt+1  
                        q.append(adj)

                if found:
                    break

            if not found:
                fail =True
                break   

        elif mat[n][m] == 1:
            any_ripen = True

if fail:
    print(-1)
elif not any_ripen:
    print(-1)
elif cnt ==0 and any_ripen:
    print(0)
else:
    print(ans)
