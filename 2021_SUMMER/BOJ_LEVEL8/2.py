N = int(input())
transform = (N + 4) // 6
if transform == 0 : print(1)
else : 
    n = 0
    while True:
        if n * (n+1) / 2 >= transform: break
        n += 1
    print(n+1)


