import sys
N = int(input())

for i in range(N):
    quiz_result = sys.stdin.readline().rstrip()
    score = 0
    count = 0
    for j in range(len(quiz_result)):
        if quiz_result[j] == 'O':
            score += (count+1)
            count += 1
        else:
            count = 0
    print(score)