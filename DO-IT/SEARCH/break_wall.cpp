#include <iostream>
#include <queue>
using namespace std;

typedef struct { int x; int y; int l; int m; } A;

char g[1000][1000];
char visited[1000][1000][2];
queue <A> q;
int N, M, i, j, nx, ny;
int ans[2] = {-1, -1};
int moves[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}; 
char c;
A * cur;

int isOk(int x, int y){ if(x >= 0 && x < N && y >= 0 && y < M) return 1; return 0;}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(i = 0 ; i < N; i++){
      for(j = 0; j < M; j++){
        cin >> c;
        g[i][j] = c - '0';
      }
    }
    visited[0][0][0] = 1;
    q.push({0, 0, 1, 0});
    while(!q.empty()){
      cur = &(q.front());
      if(cur->x == N-1 && cur->y == M-1)
        ans[cur->m] = cur->l;
      for(i = 0; i < 4; i++){
        nx = cur->x + moves[i][0]; ny = cur->y + moves[i][1];
        if(isOk(nx, ny)){
          if(g[nx][ny] && cur->m == 0 && !visited[nx][ny][1]){
            visited[nx][ny][1] = 1;
            q.push({nx, ny, cur->l + 1, 1});
          }
          if(!g[nx][ny] && !visited[nx][ny][cur->m]){
            visited[nx][ny][cur->m] = 1;
            q.push({nx, ny, cur->l + 1, cur->m});    
          }
        }
      }
      q.pop();
    }

    if(ans[0] < 0 && ans[1] < 0)
      cout << -1 << endl;
    else if(ans[0] * ans[1] > 0)
      cout << (ans[0] < ans[1] ? ans[0] : ans[1]) << endl;
    else
      cout << (ans[1] < 0 ? ans[0] : ans[1] ) << endl;

    return 0;
}
