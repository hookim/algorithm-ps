#include <iostream>
#include <vector>

using namespace std;

vector<int> g[2000];
int visited[2000];
int reached;

void dfs(int f, int l){
  visited[f] = 1;

  if(l == 4 || reached){
    reached = 1;
    return;
  }
  for(auto v: g[f]){
    if(!visited[v])
      dfs(v, l+1);
  }
  visited[f] = 0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, idx, a, b;
    cin >> N >> M;

    for (idx = 0; idx < M; idx++){
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    for(idx = 0; idx < N; idx++){
      dfs(idx, 0);
      if(reached){
        cout << "1" << endl;
        return 0;
      }
    }
    cout << "0" << endl;
    return 0;
}
