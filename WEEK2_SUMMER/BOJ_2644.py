# how close to my family

from collections import deque

N = int(input())
src, dest = list(map(int, input().split(' ')))
E = int(input())

adj_list= []
for n in range(N):
    adj_list.append([])


for e in range(E):
    a, b = list(map(int, input().split(' ')))
    adj_list[a-1].append(b)
    adj_list[b-1].append(a)

visited =[0] * N
stack = deque()
stack.append(src)
close_stack = deque()
close_stack.append(0)
ans = -1

while len(stack) > 0:
    cur = stack.pop()
    close = close_stack.pop()

    if not visited[cur-1]:
        visited[cur-1] = 1    
        
        if cur == dest:
            ans = close
            break 

        for i in range(len(adj_list[cur-1])):

            stack.append(adj_list[cur-1][i])
            close_stack.append(close+1)

print(ans)




