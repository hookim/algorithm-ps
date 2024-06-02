#include <iostream>
#include <queue>
#include <vector> 
#include <algorithm>

using namespace std;

int R, C, K, r1, c1, r2, c2, ans;
int arr[101][101];
bool visited[101][101];
vector<int> v;

int dR[] = {0, 1, -1, 0};
int dC[] = {1, 0, 0, -1};

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    int area = 0;

    while(!q.empty()){
        int cR = q.front().first;
        int cC = q.front().second;

        q.pop();
        area++;

        for(int d =0 ; d < 4; d++){
            int nR = cR + dR[d];
            int nC = cC + dC[d];

            if(nR < 0 || nR >= R || nC < 0 || nC >= C)
                continue;
            if(visited[nR][nC] || arr[nR][nC])
                continue;
            
            visited[nR][nC] = true;
            q.push({nR, nC});
        }
    }

    v.push_back(area);

}


void solve(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(visited[i][j] || arr[i][j])
                continue;

            visited[i][j] = true;
            bfs(i, j);
        }
    }
}


int main(void){

    cin >> R >> C >> K;
    for(int i = 0 ; i < K; i++){
        cin >> c1 >> r1 >> c2 >> r2;

        for(int i = r1; i < r2; i++){
            for(int j = c1; j < c2; j++){
                arr[i][j]++;
            }
        }
    }
    
    solve();
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";

    return 0;
}

