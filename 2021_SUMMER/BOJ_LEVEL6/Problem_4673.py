list = [0] * 10000

def d_serial(n, list):
    if n > len(list): return
    list[n-1] = 1               

    if n < 10:  d_serial( n + n , list)
    elif n < 100: d_serial( n + n % 10 + n // 10 , list )
    elif n < 1000: d_serial( n + n % 10 + n // 10 % 10 + n // 100, list)
    elif n < 10000: d_serial(n + n % 10 + n // 10 % 10 + n // 100 % 10 + n // 1000, list)
    
for i in range(len(list)):
    if list[i] == 0 or i ==0 :
        d_serial(i+1,list)
        print(i+1)