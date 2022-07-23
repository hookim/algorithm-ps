#Naming Building Number

if __name__ == '__main__':
    N = int(input())
    mat = []
    visited = []
    for i in range(N):
        mat.append(list(map(int, list(input()))))
        visited.append([0] * N)
    move_around = [(0,1), (1,0), (-1,0), (0,-1)]
    buildings = []

    for i in range(N):
        for j in range(N):
            if mat[i][j] == 1 and not visited[i][j]:
                stack = [(i,j)]
                count = 0
                while len(stack) > 0:
                    cur = stack.pop()
                    if mat[cur[0]][cur[1]] and not visited[cur[0]][cur[1]]:
                        visited[cur[0]][cur[1]] = 1
                        count += 1
                        for move in move_around:
                            adj_row = cur[0] + move[0]
                            adj_col = cur[1] + move[1]
                            if adj_row >= 0 and adj_row < N and adj_col >= 0 and adj_col < N and mat[adj_row][adj_col] == 1:
                                stack.append((adj_row, adj_col))

                buildings.append(count)

    buildings.sort()
    length = len(buildings)
    print (length)
    for i in range(length):
        print(buildings[i])
