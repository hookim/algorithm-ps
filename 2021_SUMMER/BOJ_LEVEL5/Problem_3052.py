import sys
remainder = [0] * 42
for i in range(10):
    remainder[int(sys.stdin.readline().rstrip()) % 42] += 1

count = 0

for i in range(42):
    if remainder[i] != 0: count += 1

print(count)
