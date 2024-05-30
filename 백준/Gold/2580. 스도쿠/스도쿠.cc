#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

vector <pair<int, int>> v;
bool check[3][9][10];
int arr[9][9];
bool flag;

void solve(int d){
    if(flag){
        return;
    }
    if(d == v.size()){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        flag = true;
        return;
    }

    for(int pick = 1; pick <= 9; pick++){
        int i = v[d].first;
        int j = v[d].second;
        if(check[0][i][pick] || check[1][j][pick] || check[2][(i/3) * 3 + j /3][pick]){
            continue;
        }

        arr[i][j] = pick;
        check[0][i][arr[i][j]] = true;
        check[1][j][arr[i][j]] = true;
        check[2][(i/3) * 3 + j /3][arr[i][j]] = true;
        
        solve(d+1);

        check[0][i][arr[i][j]] = false;
        check[1][j][arr[i][j]] = false;
        check[2][(i/3) * 3 + j /3][arr[i][j]] = false;
        arr[i][j] = 0;

        if(flag){
            return;
        }

    }
}

int main(void){

    for(int i = 0 ; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0){
                v.push_back({i, j});
            }
            else{
                check[0][i][arr[i][j]] = true;
                check[1][j][arr[i][j]] = true;
                check[2][(i/3) * 3 + j /3][arr[i][j]] = true;
            }
        }
    }

    solve(0);
    return 0;
}

