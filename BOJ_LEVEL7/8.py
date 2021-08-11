str = input()

#short and compact version
let_List = ["c=","c-","dz=","d-","lj","nj","s=","z="]

for i in let_List:
    str= str.replace(i, '*')
print(len(str))

#longer verstion
check = [False] * len(str)

for i in range(len(str)):
    if str[i] == "=" and i >= 1 :
        if(str[i-1] == "c" or str[i-1] == "s"): continue
        
        elif (str[i-1] == "z"):
            if i >= 2 and str[i-2] == "d": 
                check[i-1] = False
            continue
       
        else: 
            check[i] = True 

    elif str[i] == "-" and i >= 1 :
        if str[i-1] == "c" or str[i-1] == "d": continue 
        
        else: check[i] = True

    elif str[i] == "j" and i >= 1:
        if str[i-1] == "l" or str[i-1] == "n": continue

        else: check[i] = True

    else:
        check[i] = True

count =0
for i in check:
    if i: count += 1
print(count)
