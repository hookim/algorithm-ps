#### NOT YET#### 

if __name__ == '__main__':
    M,N = list(map(int, input().split(' ')))
    mat = []
    dist = []
    visited = []
    for n in range(N):
        mat.append(list(map(int, input().split(' '))))
    
    possible_answers = []
    move_around = [(0,1), (1,0), (-1,0), (0,-1)]
    any_ripen = False
    any_unripen = False

    for n in range(N):
        for m in range(M):

            found = True 
            if mat[n][m] == 1:
                any_ripen = True

            if mat[n][m] == 0:
                found = False
                for n in range(N):
                    visited.append([0] * M)

                any_unripen = True
                queue = [(n,m)]
                src_queue = [(n,m)]
                dist_queue = [0]

                while len(queue) > 0:

                    cur = queue.pop(0)
                    src = src_queue.pop(0)
                    cur_dist = dist_queue.pop(0)

                    if mat[cur[0]][cur[1]] == 1:
                        found = True
                        possible_answers.append(cur_dist)
                        break

                    if mat[cur[0]][cur[1]] == 0:
                        visited[cur[0]][cur[1]] = 1

                        for move in move_around :
                            adj = (cur[0] + move[0], cur[1] + move[1])

                            if adj[0] >= 0 and adj[0] < N and adj[1] >= 0 and adj[1] < M and mat[adj[0]][adj[1]] != -1\
                                and adj not in queue and not visited[adj[0]][adj[1]]:
                                queue.append(adj)
                                src_queue.append(cur)
                                dist_queue.append(cur_dist + 1)

            if found == False:
                any_ripen = False
                break
                
    if not any_ripen:
        print(-1)
    elif not any_unripen:
        print(0)
    else:
        possible_answers.sorted()
        if possible_answers[0] == 0:
            print(-1)
        else:
            print (possible_answers[-1])


    
                                







