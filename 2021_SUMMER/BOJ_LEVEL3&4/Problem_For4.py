#2438
T = int(input())
# for i in range(T):
#     print('*' * (i+1))
#2439
for i in range(T):
    print('{:>{x}}'.format('*'*(i+1), x = T))