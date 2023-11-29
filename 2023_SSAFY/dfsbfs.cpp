#include <iostream>
#include <stack>
#include <queue>

using namespace std;

short g[1000][1000], checkDfs[1000], checkBfs[1000];
int V, E, A, a, b;
stack<int> s;
queue<int> q; 

void dfs(){
  s.push(A-1);
  while(!s.empty()){
    int cur = s.top();
    s.pop();

    if(!checkDfs[cur]){
      checkDfs[cur] = 1;
      cout << cur+1 << " ";

      for(int i = V-1; i >= 0; i--){
        if(g[cur][i])
          s.push(i);
      }
    }
  }
}

void bfs(){
  q.push(A-1);
  checkBfs[A-1] = 1;

  while(!q.empty()){
    int cur = q.front();
    q.pop();
    cout << cur+1 << " ";

    for(int i = 0; i < V; i++){
      if(g[cur][i] && !checkBfs[i]){
        checkBfs[i] = 1;
        q.push(i);
      }
    }
  }
}

void solution(){
  cin >> V >> E >> A;
  for(int i = 0; i < E; i++){
    cin >> a >> b;
    g[a-1][b-1] = 1;
    g[b-1][a-1] = 1;
  }
  dfs();
  cout << "\n";
  bfs();
  cout << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
