#include <iostream>
#include <vector>

using namespace std;

int V, E, a, b, ans, f;

vector<int> g[1000];
short check[1000];

void dfs(int i){
  if(check[i]) return;
  check[i] = 1;
  f = true;
  for(auto el : g[i]){
    dfs(el);
  }
}

void solution(){
  cin >> V >> E;
  for(int i = 0; i < E; i++){
    cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }
  for(int i = 0; i < V; i++){
    dfs(i);
    if(f) ans ++;
    f = false;
  }

  cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
