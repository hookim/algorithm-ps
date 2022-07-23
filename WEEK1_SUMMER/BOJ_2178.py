#MAZE SEARCH

from operator import not_


if __name__ == '__main__':
    N, M = map(int, input().split(' '))

    G = []
    visited = []
    dist = []
    for n in range(N):
        G.append(list(map(int, list(input()))))
        visited.append([0]* M)
        dist.append([0] * M)
        

    move_coord = [(1,0), (-1,0), (0,1), (0,-1)]
    cur = (1,1)
    prev = (1,1)
    queue = [cur]
    src_queue = [prev]
    
    while True:
        coord = queue.pop(0)
        src = src_queue.pop(0)
        row = coord[0]
        col = coord[1]
        if G[row-1][col-1] and not visited[row-1][col-1]:
            dist[row-1][col-1] = dist[src[0]-1][src[1]-1] + 1
            visited[row-1][col-1] = 1

            if coord == (N, M):
                break
            
            for move in move_coord:
                adj_coord = (row + move[0], col + move[1])
                adj_row = adj_coord[0]
                adj_col = adj_coord[1]
                if adj_row >= 1 and adj_row <= N and adj_col >= 1 and adj_col <= M:
                    if adj_coord not in queue:
                        queue.append(adj_coord)
                        src_queue.append(coord)

    print(dist[N-1][M-1])
                    
                

