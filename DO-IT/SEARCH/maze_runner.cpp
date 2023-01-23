#include <iostream>
#include <queue>

using namespace std;

char g[100][100];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    char c;
    int N, M, i, j, a, b, cur_dis;
    queue <pair <int, int> > q;
    queue <int> d;
    pair<int, int> coord, next;
    int move[4][2] = {{0, 1}, {0, -1} ,{1, 0}, {-1, 0}};

    cin >> N >> M;
    for(i = 0; i < N ; i++){
      for(j = 0; j < M; j++){
        cin >> c;
        g[i][j] = c - '0';
      }
    }
  
    q.push(make_pair(0,0)); d.push(1); g[0][0] = 0;
    while(!q.empty()){
      coord = q.front(); q.pop();
      cur_dis = d.front(); d.pop();

      if(coord.first == N-1 && coord.second == M-1){
        cout << cur_dis << endl;
        break;
      }
      for(i = 0 ; i < 4; i++){
        a = move[i][0] + coord.first;
        b = move[i][1] + coord.second;
        if(a >= 0 && a < N && b >= 0 && b < M && g[a][b]){
          g[a][b] = 0; q.push(make_pair(a,b)); d.push(cur_dis+1);
        }
      }
    }

    return 0;
}
