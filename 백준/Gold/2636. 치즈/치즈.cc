#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int arr[100][100];
bool visited[100][100];

int dN[] = {0, 0, 1, -1};
int dM[] = {1, -1, 0, 0};
int t, prevCnt, cnt;

bool solve(){
  bool ret = false;
  cnt = 0;
  queue<pair<int, int>> q;
  q.push({0, 0});
  visited[0][0] = true;
  t++;

  while(!q.empty()){

    int n = q.front().first;
    int m = q.front().second;
    q.pop();
    for(int d = 0 ; d < 4; d++){
      int nN = n + dN[d];
      int nM = m + dM[d];

      if(nN < 0 || nN >= N || nM < 0 || nM >= M)
        continue;
      if(visited[nN][nM])
        continue;

      visited[nN][nM] = true;

      if(arr[nN][nM] == 1){
        ret = true;
        arr[nN][nM] = 0;
        cnt++;
        continue;
      }
      q.push({nN, nM});
    }
  }
  return ret;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0 ; i < N; i++){
      for(int j = 0; j < M; j++){
        cin >> arr[i][j];
      }
    }

    while(solve()){
      memset(visited, false, sizeof(visited));
      prevCnt = cnt;
    }

    cout << t-1 << "\n" << prevCnt << "\n";
    return 0;
}
