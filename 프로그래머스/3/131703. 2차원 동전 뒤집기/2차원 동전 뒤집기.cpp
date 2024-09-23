#include <string>
#include <vector>

using namespace std;

/* 
    동전 뒤집기의 마법
1. 넘기는 순서는 중요하지 않아요.
2. 처음, 목표 동전의 배치를 비교한 차이를 활용합니다.
3. 어떤 줄을 2번 이상 넘겨야 하는 경우가 있을까요? -> 아뇨. 무의미합니다. 
*/

int diff[10][10];
int R, C;
int ans;

void flipArr(bool isRow, int n){
    if(isRow){
        for(int i = 0 ; i < C; i++){
            diff[n][i] ^= 1;
        }    
    }
    else{
        for(int i = 0 ; i < R; i++){
            diff[i][n] ^= 1;
        }    
    }
    
}


void diffArr(vector<vector<int>> beginning, vector<vector<int>> target){
    for(int i = 0 ; i < beginning.size(); i++){
        for(int j = 0 ; j < beginning[0].size(); j++){
            diff[i][j] = beginning[i][j] ^ target[i][j];
        }
    }
}

void solve(int n, int depth){
    bool everythingEqual = true;
    for(int i = 0 ; i < R; i++){
        for(int j = 0 ; j < C; j++){
            if(diff[i][j]){
                everythingEqual = false;
                break;
            }
        }
        if(!everythingEqual) break;
    }
    if(everythingEqual){
        if(ans == -1 || ans > depth)
            ans = depth;
        return ;
    }
    
    if(n == R + C) return;
                        
    if(n < R){
        flipArr(true, n);
        solve(n+1, depth+1);
        flipArr(true, n);
    }

    if(n >= R){
        flipArr(false, n-R);
        solve(n+1, depth+1);
        flipArr(false, n-R);
    }
    
    solve(n+1, depth);
}


int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    ans = -1;
    R = beginning.size();
    C = beginning[0].size();
    diffArr(beginning, target);
    
    solve(0, 0);   
    
    return ans;
}