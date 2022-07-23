import sys

N = int(input())
scores = sys.stdin.readline().rstrip().split(' ')
max = 0
sum = 0

for i in range(N):
    scores[i] = int(scores[i])
    sum += scores[i]
    if scores[i] > max : max = scores[i]

print(100 * sum / (N * max))

