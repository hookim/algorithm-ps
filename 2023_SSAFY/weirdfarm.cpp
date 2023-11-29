#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int T, N, x, y, r;
short farm[50][50];
char c;
int dir[4][2] = {{0,1}, {0, -1}, {-1, 0}, {1, 0}};
queue <tuple<int, int, int> > q;

void solution(){
  cin >> T; 
  for(int t = 0; t < T; t++){
    cin >> N;
    int ans = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        cin >> c;
        farm[i][j] = c - '0';
      }
    }
    ans = farm[N/2][N/2];
    farm[N/2][N/2] = -1;
    q.push(make_tuple(N/2, N/2, 0));
    while(!q.empty()){
      tie(x,y,r) = q.front();
      q.pop();
      for(int d = 0; d < 4; d++){
        int nextX = x + dir[d][0];
        int nextY = y + dir[d][1];
        if(farm[nextX][nextY] >= 0 && r <= (N/2)-1){
          ans += farm[nextX][nextY];
          farm[nextX][nextY] = -1;
          q.push({nextX, nextY, r+1});
        }
      }
    }
    cout << "#" << t << " " << ans << "\n"; 
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
