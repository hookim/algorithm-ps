#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

int T, M, N, K, r, c, ans;
bool arr[50][50];
int dX[] = {0, 1, -1, 0};
int dY[] = {1, 0, 0, -1};
queue<pair<int, int>> q;

void bfs(int r, int c ){
  q.push({r, c});
  arr[r][c] = false;
  int curR,curC;
  while(!q.empty()){
    tie(curR,curC) = q.front();
    q.pop();
    
    for(int i = 0; i < 4; i++){
      int newR = curR + dY[i];
      int newC = curC + dX[i];
      if(newR < 0 || newR >= N || newC < 0 || newC >= M)
        continue;
      if(!arr[newR][newC])
        continue;

      arr[newR][newC] = false;
      q.push({newR, newC});
    }

  }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    for(int t = 0; t < T; t++){
      cin >> M >> N >> K;
      for(int i = 0 ; i < K; i++){
        cin >> c >> r;
        arr[r][c] = true;
      }
      ans = 0;
      for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
          if(!arr[i][j])
            continue;
          bfs(i, j);
          ans++;
        }
      }
      cout << ans << "\n";

    }

    return 0;
}

