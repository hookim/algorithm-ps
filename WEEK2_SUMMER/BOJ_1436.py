N = int(input())

begin = ((N-1)//20) * 10
offset = (N-1) % 20

if  6 <= offset <16:
    offset -= 6
    ans = str((offset+begin) // 10) + '666' + str((offset+begin) % 10)
if offset >= 16:
    offset -= 10
    ans = str(offset+begin) + '666'
else:
    ans = str(offset+begin) + '666'
print(int(ans))

