import sys

idx = 1
x = int(sys.stdin.readline().rstrip())
max = x

for i in range(8):
    x = int(sys.stdin.readline().rstrip())
    if x > max:
        max = x
        idx = i+2

print(max)
print(idx)