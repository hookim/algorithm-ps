#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int R, C, curR, curC, curD, fire, ans;
string row;
vector<pair<int,int>> fires;
int dR[] = {0, 1, -1, 0};
int dC[] = {1, 0, 0, -1};
int arr[1000][1000];

void solve(){
    queue<tuple<int, int, int, int>> q;

    for(auto f : fires){
        q.push(make_tuple(f.first, f.second, 0, 1));
    }
    q.push(make_tuple(curR, curC, 0, 0));

    while(!q.empty()){
        tie(curR, curC, curD, fire) = q.front();
        q.pop();

        for(int d = 0; d < 4; d++){
            int nextR = curR + dR[d];
            int nextC = curC + dC[d];

            if(fire){
                if(nextR < 0 || nextC < 0 || nextR >=R || nextC >= C) continue;
                if(arr[nextR][nextC] < 0) continue;
                arr[nextR][nextC] = -1;
                
            }
            else{
                if(nextR < 0 || nextC < 0 || nextR >=R || nextC >= C){
                    ans = curD + 1;
                    return;
                }
                if(arr[nextR][nextC] < 0) continue;
                if(arr[nextR][nextC] > 0 && arr[nextR][nextC] <= curD+1) continue;
                arr[nextR][nextC] = curD + 1;
            }
            q.push(make_tuple(nextR, nextC, curD+1, fire));

        }
    }
}

int main(void){
    cin >> R >> C;

    for(int i = 0; i < R; i++){
        cin >> row;
        for(int j = 0; j < C; j++){
            char c = row[j];
            if(c == '#'){
                arr[i][j] = -1;
            }
            if(c == 'J'){
                curR = i;
                curC = j;
            }
            if(c == 'F'){
                arr[i][j] = true;
                fires.push_back({i, j});
            }
        }
    }

    solve();
    if(ans){
        cout << ans << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}