# DFS and BFS

if __name__ == '__main__':
    N, M, V = map(int, input().split(' '))
    G = []
    for n in range(N):
        G.append([0] * N)

    for m in range(M):
        a, b  = map(int, input().split(' '))
        G[a-1][b-1] = 1
        G[b-1][a-1] = 1
    
    # DFS
    stack = [V]
    visited_DFS = [0] * N
   
    while len(stack) > 0:
        cur_node = stack.pop()
        if not visited_DFS[cur_node-1]:
            visited_DFS[cur_node-1] = 1
            print(cur_node, end=' ')

            for i in range(N-1, -1, -1):
                if G[cur_node - 1][i]:
                    stack.append(i+1)
    print()

    #BFS
    queue = [V]
    visited_BFS = [0] * N

    while len(queue) > 0:
        cur_node = queue.pop(0)
        if not visited_BFS[cur_node-1]:
            visited_BFS[cur_node-1] = 1
            print(cur_node, end = ' ')

            for i in range(N):
                if G[cur_node - 1][i] and i+1 not in queue:
                    queue.append(i+1)
    print()
        

    

    
