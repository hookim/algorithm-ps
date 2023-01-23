#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[5][20000];
short visited [5][20000];
queue<int> q;
int K, V, E, i, j, k, a, b, isCycle;

void bfs(int tc, int start){
  if(visited[tc][start]) return;
  int cur, cur_col;

  q.push(start);
  visited[tc][start] = 1;
  while(!q.empty()){
    cur = q.front(); q.pop();
    cur_col = visited[tc][cur];
    for(auto v : g[tc][cur]){
      if(!visited[tc][v]){
        visited[tc][v] = -cur_col;
        q.push(v);
      }
      if(cur_col == visited[tc][v]){
        isCycle = 1;
        while(!q.empty())
          q.pop();
        break;
      }
    }
  }

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K;
    for(i = 0; i < K; i++){
      cin >> V >> E;
      for(j = 0; j < E; j++){
        cin >> a >> b;
        g[i][a-1].push_back(b-1);
        if(a != b)
          g[i][b-1].push_back(a-1);
      }
    }

    for(k = 0; k < K; k++){
      isCycle = 0;
      for(i = 0; i < V && !isCycle; i++){
        bfs(k, i);
      }
      if(isCycle) cout << "NO" << endl;
      else cout << "YES" << endl;
    }

    return 0;
}
