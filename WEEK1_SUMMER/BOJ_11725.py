# finding parent nodes
from collections import deque

N = int(input())
conn =[]
ans = [0] * N 

for n in range(N):
    conn.append([])

for n in range(N-1):
    a, b = list(map(int, input().split(' ')))
    conn[a-1].append(b)
    conn[b-1].append(a)

stack = deque()
stack.append(1)

parent = deque()
parent.append(1)

prev = 1
cur = 1

while len(stack) > 0 :
    cur = stack.pop()
    par = parent.pop()

    if ans[cur-1] == 0:
    
        ans[cur-1] = par

        for i in range(len(conn[cur-1])):
            stack.append(conn[cur-1][i])
            parent.append(cur)

for i in range(1, N):
    print(ans[i])

