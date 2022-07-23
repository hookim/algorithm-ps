import sys

N = int(input())
count = 0

def is_group(str):
    check = []
    for i in range(len(str)):
        if str[i] in check:
            if str[i] == str[i-1]: continue
            else: return False
        else: check.append(str[i])
    return True

for i in range(N):
    str = sys.stdin.readline().rstrip()
    if is_group(str): count += 1
    
print(count)  
