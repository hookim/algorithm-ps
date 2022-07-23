# marine area
import sys 

if __name__ == '__main__':
    while True:
        W,H = list(map(int, sys.stdin.readline().split(' ')))
        if W == 0 and H == 0:
            break
        mat = []
        visited= []
        
        for h in range(H):
            mat.append(list(map(int, sys.stdin.readline().split(' '))))
            visited.append([0] * W)

        move_around = [(0,1), (0,-1), (1,0), (-1,0), (1,1),(-1,-1),(-1,1),(1,-1)]
        num_of_islands = 0
        
        for w in range(W):
            for h in range(H):
                queue = [(h,w)]
                if mat[h][w] == 1 and not visited[h][w]:
                    num_of_islands += 1
                    while len(queue) > 0:
                        cur = queue.pop(0)
                        if mat[cur[0]][cur[1]] == 1 and not visited[cur[0]][cur[1]]:
                            visited[cur[0]][cur[1]] = 1
                            for move in move_around:
                                adj = (cur[0] + move[0], cur[1] + move[1])
                                if adj[0] >= 0 and adj[0] < H and adj[1] >= 0 and adj[1] < W and adj not in queue:
                                    queue.append(adj)
        print(num_of_islands)


        
