#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool visited[8][8];
int arr[8][8];
int N, M, ans, safeArea;
vector<pair<int, int> > virus, walls;
bool picks[64];

int dR[] = {0, 1, -1, 0};
int dC[] = {1, 0, 0, -1};

void bfs(int r, int c){
  queue<pair <int, int> > q; 
  
  visited[r][c] = true;
  q.push({r, c});
  
  while(!q.empty()){
    int curR = q.front().first;
    int curC = q.front().second;
    q.pop();

    for(int d = 0 ; d < 4; d++){
      int nR = curR + dR[d];
      int nC = curC + dC[d];

      if(nR < 0 || nR >= N || nC < 0 || nC >= M )
        continue;
      if(visited[nR][nC])
        continue;
      if(arr[nR][nC] == 1)
        continue;
      visited[nR][nC] = true;
      q.push({nR, nC});
    }
  }
  
  ans = max(safeArea, ans);


}

void solve(int d, int start){
  if(d == 3){
    safeArea = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < walls.size(); i++){
      if(picks[i]){
        visited[walls[i].first][walls[i].second] = true;
      }
    }

    for(int i = 0; i < virus.size(); i++){
      if(visited[virus[i].first][virus[i].second])
        continue;
      bfs(virus[i].first, virus[i].second);

    }
    for(int i = 0; i < N; i++){
      for(int j = 0 ;j < M; j++){
        if(!visited[i][j] && arr[i][j] == 0){
          safeArea++;
        }
      }
    }
    ans = max(ans, safeArea);

    return;
  }

  for(int i = start; i < walls.size(); i++){
    if(picks[i])
      continue;
    
    picks[i] = true;
    solve(d+1, i+1);
    picks[i] = false;
  }
}


int main(void){
  cin >> N >> M;
  for(int i = 0 ; i < N ; i++){
    for(int j = 0;  j < M; j++){
      cin >> arr[i][j];
      if(arr[i][j] == 2)
        virus.push_back({i, j});
      if(arr[i][j] == 0)
        walls.push_back({i, j});
    }
  }
  


  solve(0, 0);
  
  cout << ans << endl;
  return 0;
}