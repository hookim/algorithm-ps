#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N , M, ans;
int arr[500][500];

int dR[] = {0, 1, -1, 0};
int dC[] = {1, 0, 0, -1};
bool visited[500][500];

void solve(int r, int c, int s, int d){
  if(d == 3){
    ans = max(s, ans);
    return;
  }

  for(int i = 0; i < 4; i++){
    int nR = r + dR[i];
    int nC = c + dC[i];

    if(nR < 0 || nR >= N || nC < 0 || nC >= M)
      continue;
    if(visited[nR][nC])
      continue;
    
    visited[nR][nC] = true;
    solve(nR, nC, s + arr[nR][nC], d+1);
    visited[nR][nC] = false;
  }

}

void solve2(int r, int c){
  vector<int> nn;

  for(int i = 0; i < 4 ; i++){
    int nR = r + dR[i];
    int nC = c + dC[i];

    if(nR < 0 || nR >= N || nC < 0 || nC >= M)
      continue;

    nn.push_back(arr[nR][nC]);
  }

  sort(nn.begin(), nn.end());
  
  if(nn.size() == 3){
    ans = max(ans, arr[r][c] + nn[0] + nn[1] + nn[2]);
  }
  if(nn.size() == 4){
    ans = max(ans, arr[r][c] + nn[1] + nn[2] + nn[3]);
  }

  return;
}

int main(void){
  cin >> N >> M;

  for(int i = 0 ; i < N; i++){
    for(int j = 0 ; j < M ; j++){
      cin >> arr[i][j];
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      visited[i][j] = true;
      solve(i, j, arr[i][j], 0);
      solve2(i, j);
      visited[i][j] = false;
    }
  }

  cout << ans << endl;


  return 0;
}