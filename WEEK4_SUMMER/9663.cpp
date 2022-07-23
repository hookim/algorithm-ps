#include <iostream>

using namespace std;

void queens(int cur_row, int N, bool chess[15][15], int& ans){

    if(cur_row == N){
        ans++;
        return;
    }
    for(int col = 0; col < N; col++){
        
        int left_dig_col = col,right_dig_col =col;
        int isSafe = 1;
        for(int row = cur_row-1; row >= 0 ; row--){
            if(--left_dig_col >= 0){
                if(chess[row][left_dig_col]){
                    isSafe = 0;
                    break;
                }
            } 
            if(++right_dig_col < N ){
                if(chess[row][right_dig_col]){
                    isSafe = 0;
                    break;
                }
            }
            if(chess[row][col]){
                isSafe = 0;
                break;
            }
        }
        if(isSafe){
            chess[cur_row][col] = 1;
            queens(cur_row+1, N, chess, ans);
            chess[cur_row][col] = 0;
        }
    }
}

int main(void){
    bool chess[15][15] = {0};
    int N;
    int ans = 0;

    cin >> N;
    queens(0, N, chess, ans);
    cout << ans << endl;

    return 0;
}
