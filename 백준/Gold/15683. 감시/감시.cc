#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <algorithm>

#define UP 1
#define RIGHT 2
#define LEFT 4
#define DOWN 8

using namespace std;

int N, M, ans = 64;
int arr[8][8];
vector<tuple<int, int, int>> cctv;
int picks[8];


int dI[] = {-1, 0, 0, 1};
int dJ[] = {0, 1, -1, 0};

int countShadeArea(){
  int cnt = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cnt += (arr[i][j] == 0 ? 1 : 0);
    }
  }
  return cnt;
}

void cctvray(int i, int j, int dir, bool cancel){
  int nI, nJ, cnt = 0;

  for(int mask = 1; mask != 1 << 4; mask = mask << 1){
    if(dir & mask ){
      nI = i + dI[cnt];
      nJ = j + dJ[cnt];
      while(nI >= 0 && nI < N && nJ >= 0 && nJ  < M ){
        if(arr[nI][nJ] == 6){
          break;
        }

        if(arr[nI][nJ] < 0 && cancel){
          arr[nI][nJ] += 1;
        }

        if(arr[nI][nJ] <= 0 && !cancel){
          arr[nI][nJ] -= 1;
        }

        nI += dI[cnt];
        nJ += dJ[cnt];
      }
    }
    cnt++;
  }
}

void solve(int d){
  int i, j, n;
  if(d == cctv.size()){
    for(int cc = 0 ; cc < cctv.size(); cc++){
      tie(i, j, n) = cctv[cc];
      cctvray(i, j, picks[cc], false);
    }

    ans = min(ans, countShadeArea());

    for(int cc = 0 ; cc < cctv.size(); cc++){
      tie(i, j, n) = cctv[cc];
      cctvray(i, j, picks[cc], true);
    }
    return;
  }

  tie(i, j, n) = cctv[d];
  if(n == 5){
    picks[d] = (UP | RIGHT | LEFT | DOWN);
    solve(d+1);
  }
  if(n == 4){
    picks[d] = (UP | RIGHT | LEFT);
    solve(d+1);
    picks[d] = (DOWN | RIGHT | LEFT);
    solve(d+1);
    picks[d] = (UP | DOWN | LEFT);
    solve(d+1);
    picks[d] = (UP | RIGHT | DOWN);
    solve(d+1);
  }
  if(n == 3){
    picks[d] = (UP | RIGHT);
    solve(d+1);
    picks[d] = (DOWN | RIGHT);
    solve(d+1);
    picks[d] = (UP | LEFT);
    solve(d+1);
    picks[d] = (DOWN | LEFT);
    solve(d+1);
  }
  if(n == 2){
    picks[d] = (UP | DOWN);
    solve(d+1);
    picks[d] = (LEFT | RIGHT);
    solve(d+1);
  }
  if(n == 1){
    picks[d] = UP;
    solve(d+1);
    picks[d] = DOWN;
    solve(d+1);
    picks[d] = RIGHT;
    solve(d+1);
    picks[d] = LEFT;
    solve(d+1);
  }
}

int main(void){

  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> arr[i][j];
      if(arr[i][j] && arr[i][j] <= 5){
        cctv.push_back(make_tuple(i, j, arr[i][j]));
      }
    }
  }
  solve(0);

  cout << ans << endl;

  return 0;
}