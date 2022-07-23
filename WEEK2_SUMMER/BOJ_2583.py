# finding area
from collections import deque
import sys

input = sys.stdin.readline

M,N,K, = list(map(int, input().rstrip().split(' ')))

g = []
for m in range(M):
    g.append([0] * N)

for k in range(K):
    x1, y1, x2, y2 = list(map(int, input().rstrip().split(' ')))
    for x in range(x1, x2):
        for y in range(y1,y2):
            g[y][x] = 1

ans=  []
moves = [(0,1), (1,0), (-1,0), (0,-1)]
for m in range(M):
    for n in range(N):
        if g[m][n] == 0:
            stack = deque()
            stack.append((m,n))
            area = 0

            while len(stack) > 0:
                cur = stack.pop()
                if g[cur[0]][cur[1]] == 0:
                    g[cur[0]][cur[1]] = -1
                    area += 1

                    for move in moves:
                        adj = (cur[0] + move[0] , cur[1] + move[1])

                        if 0 <= adj[0] < M and 0 <= adj[1] < N:
                            stack.append(adj)
            ans.append(area)

ans.sort()
n = len(ans)
print (n)
for i in range(n):
    print(ans[i], end = ' ')
print()
