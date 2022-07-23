# connected component
import sys

if __name__ == '__main__':
    N,M = list(map(int, sys.stdin.readline().split(' ')))
    adj_list= []

    for n in range(N):
        adj_list.append([])
    for m in range(M):
        a, b = list(map(int, sys.stdin.readline().split(' ')))
        adj_list[a-1].append(b)
        adj_list[b-1].append(a)
    
    visited =[0] * N
    count = 0
    
    for n in range(1,N+1):
        queue = [n]
        if not visited[n-1]:   
            count += 1
            
            while len(queue) > 0 :
                cur = queue.pop(0)
                if not visited[cur-1]:
                    visited[cur-1] = 1
                    for adj in adj_list[cur-1]:
                        if adj not in queue:
                            queue.append(adj)
    print(count)
