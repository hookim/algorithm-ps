#2675
import sys

T = int(input())

for i in range(T):
    info = sys.stdin.readline().rstrip().split()
    R = int(info[0])
    S = str(info[1])
    for j in range(len(S)):
        print(S[j] * R, end ="")
    print()

