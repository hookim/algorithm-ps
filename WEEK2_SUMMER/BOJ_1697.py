# Catch that Cow
from collections import deque

john, cow = list(map(int, input().split(' ')))

q = deque()
q.append((john, 0))

ans = 0
visited = [0] * ((10**5)+1)  
while len(q) > 0:
    cur, dist = q.popleft()
    if cur == cow:
        ans = dist
        break
    visited[cur] = 1

    moves =(1,-1,cur)
    for i in range(3):
        next = cur + moves[i]
        if 0 <= next <= 100000 and not visited[next]:
             q.append((next, dist+1))
print(ans)

    