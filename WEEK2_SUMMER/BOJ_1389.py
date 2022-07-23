# Kevin Bacon?
from collections import deque

N, M = list(map(int, input().split(' ')))
mat = []
for n in range(N):
    mat.append([0] * N)
for m in range(M):
    a,b = list(map(int, input().split(' ')))
    mat[a-1][b-1] = 1
    mat[b-1][a-1] = 1

min_kevins = 999999
idx = -1
for src in range(1,N+1):
    visited = [0] * N

    q = deque()
    dist_q = deque()
    q.append(src)
    dist_q.append(0)
    kevin = 0

    
    while len(q) > 0:
        cur = q.popleft()
        cur_kevin = dist_q.popleft()
        kevin += cur_kevin
       
        for i in range(N):
            if mat[cur-1][i] == 1:
                if not visited[i]:
                    visited[i] = 1
                    q.append(i+1)
                    dist_q.append(cur_kevin+1)

    if min_kevins > kevin:
        min_kevins = kevin
        idx = src
print(idx)