# non flooded area
from collections import deque
import sys

if __name__ == '__main__':
    N = int(sys.stdin.readline())
    mat = []
    visited = []
    hmax = 1
    hmin = 100
    for n in range(N):
        mat.append(list(map(int, sys.stdin.readline().split(' '))))
        visited.append([0] * N)
       
    move = [(0,1), (0,-1), (1,0), (-1,0)]
    max_areas = 0

    for rain in range(0,100):
        areas = 0
        
        for i in range(N):
            for j in range(N):
                
                if mat[i][j] > rain and not visited[i][j]:
                    areas += 1
                    queue = deque()
                    queue.append((i,j))

                    while len(queue) > 0:
                        cur = queue.popleft()
                        
                        if mat[cur[0]][cur[1]] > rain and not visited[cur[0]][cur[1]]:
                            visited[cur[0]][cur[1]] = 1
                            
                            for move_around in move:
                                adj = (cur[0] + move_around[0], cur[1] + move_around[1])
                                if adj[0] >= 0 and adj[0] < N and adj[1] >= 0 and adj[1] < N and adj not in queue:
                                    queue.append(adj)
        if areas == 0:
            break

        if areas > max_areas:
            max_areas = areas

        visited =[]
        for i in range(N):
            visited.append([0] * N)
                    
    
    print (max_areas)




