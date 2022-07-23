#include <deque>
#include <iostream>

using namespace std;

int main(void){
    short bd [101][101] = {0}; //1-base , 0 empty, 1 occupied, 2 apple
    int N,A, a,b;
    scanf("%d", &N);
    scanf("%d", &A);
    for(int i = 0; i < A; i++){
        scanf("%d %d", &a, &b);
        bd[a][b] =2;
    }
    int C, s;
    char m;
    deque < pair <int, char> > commands; 
    scanf("%d", &C);
    for(int i =0; i < C; i ++){
        scanf("%d %c", &s, &m);
        pair < int, char > p = make_pair(s,m);
        commands.push_back(p);
    }

    int next_sec, next_turn;

    if (!commands.empty()){
        next_sec = commands.front().first;
        next_turn = commands.front().second;
        commands.pop_front();
    }else
        next_sec = -1;
    
    
    deque < pair <int, int> > snake;
    pair < int, int >  p = make_pair(1, 1);
    snake.push_back(p);
    bd[1][1] = 1;
    int ans = 0;
    int cur[2] = { 1, 1 };
    int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int di = 0;
    while(true){
        cur[0] = cur[0] + move[di][0];
        cur[1] = cur[1] + move[di][1];        
        
        //if cur is invalid then break print ans
        if(cur[0] < 1 || cur[0] > N || cur[1] < 1 || cur[1] > N || bd[cur[0]][cur[1]] == 1){
            printf("%d\n", ans+1);
            break;
        }

        //check if an apple is located in cur
        p = make_pair(cur[0], cur[1]);
        snake.push_back(p);
        ans += 1;
        if(!bd[cur[0]][cur[1]]){
            bd[snake.front().first][snake.front().second] = 0;
            snake.pop_front();
        }
        bd[cur[0]][cur[1]] = 1;

        //check if any command to execute
        if(ans == next_sec){
            if(next_turn == 'L')
                di =(di + 3) % 4;
            else
                di = (di + 5) % 4;

            if (!commands.empty()){
                next_sec = commands.front().first;
                next_turn = commands.front().second;
                commands.pop_front();
            }else
                next_sec =-1;
        }
    }

    return 0;
}
