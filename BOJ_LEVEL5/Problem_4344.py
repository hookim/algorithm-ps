import sys
C = int(input())

for i in range(C):
    info = sys.stdin.readline().rstrip().split(' ')
    total = int(info[0])
    scores = info[1: len(info)]
    sum=0
    for j in range(len(scores)):
        sum += int(scores[j])
    avg = sum / total
    more_than_avg = 0
    for j in range(len(scores)):
        if int(scores[j]) > int(avg): more_than_avg += 1
    print("%.3f%%" % float(100 * more_than_avg / total))
