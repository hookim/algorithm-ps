#10809

frq = [-1] * (ord('z') - ord('a') + 1)
transform = ord('a')

str = input()

for i in range(len(str)):
    if frq[ord(str[i]) - transform] == -1:
        frq[ord(str[i]) - transform] = i
    
for i in frq:
    print(i , end = " ")
