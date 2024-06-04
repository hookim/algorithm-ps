#include <iostream>
#include <vector> 
#include <algorithm>
#include <queue>
#include <tuple>
#define MAX 40001

using namespace std;

int W, H, K;
int cnt[200][200][31], arr[200][200];
int dR[] = {0, -1, 0, 1};
int dC[] = {1, 0, -1, 0};
int dHR[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dHC[] = {2, -2, 2, -2, 1, -1, 1, -1};

void Init(){
    for(int i = 0 ; i < H; i++){
        for(int j = 0; j < W; j++){
            for(int k = 0; k <= K; k++){
                cnt[i][j][k] = MAX;

            }
        }
    }

}

void solve(){
    queue<tuple<int, int, int, int> > q; 
    
    cnt[0][0][K] = 0;
    q.push(make_tuple(0, 0, 0, K));
    while(!q.empty()){
        int cR, cC, cM, cK;
        tie(cR, cC, cM, cK) = q.front();
        q.pop();

        for(int d = 0; d < 4; d++){
            int nR = cR + dR[d];
            int nC = cC + dC[d];

            if(nR < 0 || nR >= H || nC < 0 || nC >= W)
                continue;
            if(cnt[nR][nC][cK] <= cM + 1)
                continue;
            if(arr[nR][nC] == 1)
                continue;
            
            cnt[nR][nC][cK] = cM + 1;
            q.push(make_tuple(nR, nC, cM +1, cK));
        }

        if(cK == 0){
            continue;
        }

        for(int d = 0; d < 8; d++){
            int nR = cR + dHR[d];
            int nC = cC + dHC[d];

            if(nR < 0 || nR >= H || nC < 0 || nC >= W)
                continue;
            if(cnt[nR][nC][cK-1] <= cM + 1)
                continue;
            if(arr[nR][nC] == 1)
                continue;
            
            cnt[nR][nC][cK-1] = cM + 1;
            q.push(make_tuple(nR, nC, cM +1, cK-1));
        }
    }


}


int main(void){

    cin >> K >> W >> H;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> arr[i][j];
        }
    }

    Init();
    solve();
    
    int ans = MAX;
    for(int i = 0 ; i <= K; i++ ){
        ans = min( ans, cnt[H-1][W-1][i] );
    }
    if(ans == MAX){
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}

