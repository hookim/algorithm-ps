#Fly me to the Alpha Centauri

if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        src, dest = list(map(int, input().split(' ')))
        dest -= src
        src = 0

        moved_dist = 0
        left_dist = dest-src
        teleport = 0

        count = 0
        
        max_reach = False 
        while True:
            if not max_reach:
                teleport += 1
            exp = teleport * (teleport + 1) / 2

            if left_dist < exp:
                max_reach = True
                teleport -= 1
            elif left_dist == exp:
                count += teleport
                break
            else:
                moved_dist += teleport
                left_dist -= teleport
                count += 1
   
        print (count) 
                    
