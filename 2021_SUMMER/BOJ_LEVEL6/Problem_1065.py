N = int(input())

def is_it (n):
    if n < 100 : 
        return True
    else :
        if 2 * (n // 10 % 10) == (n // 100 + n % 10): return True
        else: return False
count = 0

for i in range(N):
    if is_it(i+1): count += 1

print(count)
