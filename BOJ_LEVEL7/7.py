str = input()

def time_taking(letter):
    ascii_number = ord(letter)
    if ascii_number <= ord('C'): return 3
    elif ascii_number <= ord('F'): return 4
    elif ascii_number <= ord('I'): return 5
    elif ascii_number <= ord('L'): return 6
    elif ascii_number <= ord('O'): return 7
    elif ascii_number <= ord('S'): return 8
    elif ascii_number <= ord('V'): return 9
    else : return 10

sum = 0
for i in str:
    sum += time_taking(i)
print(sum)