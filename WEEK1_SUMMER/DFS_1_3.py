counter = 0

if __name__ == '__main__':
    V = int(input())
    E = int(input())
    
    v_list = []
    # generating adjacent list
    for  v in range(V):
        v_list.append([])
    for e in range(E):
        a, b = map(lambda x : int(x), input().split(' '))
        v_list[a-1].append(b)
        v_list[b-1].append(a)

    visited = [0] * V
    stack = []
    # At first, configuring for the very first node # 1
    for j in range(len(v_list[0])):
        stack.append(v_list[0][j])
    
    # Mark as visited
    visited[0] = 1

    # this loop is valid while stack is not empty
    while len(stack) > 0:
        cur_node = stack.pop()
        # only process for the unvisited ones
        if not visited[cur_node-1]:
            counter += 1
            visited[cur_node-1] = 1
            
            #check for the adjacent nodes of the node popped out of the stack
            for k in range(len(v_list[cur_node-1])):
                cur_next_node = v_list[cur_node - 1][k]
                # if not in the stack and not visited then push to the stack
                if cur_next_node not in stack:
                    stack.append(cur_next_node)

    print (counter)
         

