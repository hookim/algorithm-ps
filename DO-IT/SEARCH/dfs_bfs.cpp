#include <iostream>
#include <queue>

using namespace std;

int g[1000][1000];
int dv[1000], bv[1000];
int N, M, s, i, a, b;

void dfs(int v){
  for(int i = 0; i < N; i++){
    if(g[v][i] && !dv[i]){
      cout << i+1 << " ";
      dv[i] = 1;
      dfs(i);
    }
  }
}

void bfs(int v){
  queue <int> Q; int p;
  Q.push(v); bv[v] = 1;
  while(!Q.empty()){
    p = Q.front(); Q.pop();
    cout << p+1 << " ";
    for(int i = 0; i < N; i++){
      if(g[p][i] && !bv[i]){
        bv[i] = 1; Q.push(i);
      }
    }
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> s;
    for(i = 0; i < M; i++){
      cin >> a >> b;
      g[a-1][b-1] = 1;
      g[b-1][a-1] = 1; 
    }
    dv[s-1] = 1;
    cout << s << " ";
    dfs(s-1);
    cout << endl;
    bfs(s-1);
    cout << endl;

    return 0;
}
