#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, L, R, day, cnt;;
int arr[50][50], newUpdated[50][50];
bool visited[50][50], flattenflag[50][50];
int dR[] = {0, 1, -1, 0};
int dC[] = {-1, 0, 0, 1};


bool flatten(int r, int c, int res){
  bool flag = false;
  queue<pair<int, int>> q;
  
  q.push({r, c});
  while(!q.empty()){
    int cR = q.front().first;
    int cC = q.front().second;
    q.pop();

    if(arr[cR][cC] != res){
      flag = true;
      newUpdated[cR][cC] = res;
    }
    
    for(int d = 0; d < 4 ; d++){
      int nR = cR + dR[d];
      int nC = cC + dC[d];

      if(nR < 0 || nR >= N || nC < 0 || nC >= N)
        continue;
      if(!flattenflag[nR][nC])
        continue;
      
      flattenflag[nR][nC] = false;
      q.push({nR, nC});
    }

  }
  return flag;

}


int bfs(int r, int c){
  queue<pair<int, int>> q;
  int cnt = 0; 
  int ssum = 0;
  q.push({r, c});
  while(!q.empty()){
    int cR = q.front().first;
    int cC = q.front().second;
    q.pop();

    ssum += arr[cR][cC];
    cnt++;

    
    for(int d = 0; d < 4 ; d++){
      int nR = cR + dR[d];
      int nC = cC + dC[d];

      if(nR < 0 || nR >= N || nC < 0 || nC >= N)
        continue;
      if(visited[nR][nC])
        continue;

      int diff = abs(arr[nR][nC] - arr[cR][cC]);
      if(diff < L || diff > R)
        continue;
      
      visited[nR][nC] = true;
      flattenflag[nR][nC] = true;
      q.push({nR, nC});
    }
  }

  return (ssum / cnt);
}

bool solve(int r, int c){
  int res = bfs(r, c);
  bool f = flatten(r, c, res);

  return f;
}

int main(void){

  cin >> N >> L >> R;

  for(int i = 0; i < N ; i++){
    for(int j = 0; j < N; j++){
      cin >> arr[i][j];
    }
  }

  for(day = 0; day < 2000; day++){
    memset(visited, false, sizeof(visited));
    memset(newUpdated, 0, sizeof(newUpdated));
    bool f = false;
    for(int i = 0 ; i < N; i++){
      for(int j = 0; j < N; j++){
        if(visited[i][j])
          continue;

        visited[i][j] = true;
        if(solve(i, j))
          f = true;
        
      }
    }
    if(!f){
      break;
    }

    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(newUpdated[i][j]!= 0){
          arr[i][j] = newUpdated[i][j];
        }
      }
    }
    
  }
  cout << day << endl;


  return 0;
}