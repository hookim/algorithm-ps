# BOJ 2606 Virus

counter = 0

def dfs(mat, idx, visited):
    global counter

    # if new node
    if visited[idx-1] == 0:
        # mark as visited
        visited[idx-1] = 1
        counter += 1
        #check for adjacent nodes
        for j in range(len(mat[idx-1])):
            #if visited and connected
            if visited[j] == 0 and mat[idx-1][j]: 
                dfs(mat, j+1, visited)
                
if __name__ == '__main__':
    V = int(input())
    E = int(input())
    
    mat = []
    for i in range(V):
        mat.append([])
        mat[i] = [0] * V

    for k in range(E):
        src,dest = list(map(lambda x : int(x), list(input().split(' '))))
        mat[src-1][dest-1] = 1
        mat[dest-1][src-1] = 1
    
    visited = [0] * V
    dfs(mat, 1, visited)
    print(counter-1)
