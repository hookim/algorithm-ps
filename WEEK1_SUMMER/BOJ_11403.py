# finding path

from collections import deque
import sys

input = sys.stdin.readline

N = int(input())
g = []
ans = []

for n in range(N):
    g.append(list(map(int, input().rstrip().split(' '))))
    ans.append([0] * N)
    
for i in range(N):
    for j in range(N):
        
        visited = [0] * N
        
        q = deque()
        q.append(i)
        visited[i] = 1

        while len(q) > 0:
            cur = q.popleft()

            for idx in range(len(g[cur])):
                if g[cur][idx] == 1:
                    if idx == j:
                        ans[i][j] = 1
                        break
                    if not visited[idx]:
                        visited[idx] = 1
                        q.append(idx)
for i in range(N):
    for j in range(N):
        print(ans[i][j] , end=' ')
    print()




    
