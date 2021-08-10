str = input().lower()
frq = [0] * (ord('z') - ord('a') + 1)
transform = ord('a')

for i in str:
    frq[ord(i) - transform] += 1

duplicate = False
max = 0

for i in range(len(frq)):
    if frq[i] == frq[max]:
        if i != 0 : duplicate = True

    elif  frq[i] > frq[max]:
        max = i 
        duplicate = False
    
    else: continue

if duplicate: print('?')
else: print(chr(max + transform).upper())