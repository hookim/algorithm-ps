#include <iostream>
#include <vector>

using namespace std;
int V, E, a, b;
int ans;

vector<int>g[2000];
short check[2000];

void dfs(int i, int depth){
  if(ans) return;
  if(depth == 5){
    ans = 1;
    return;
  }
  for(const auto & val : g[i]){
    if(!check[val]){
      check[val] = 1;
      dfs(val, depth+1);
      check[val] = 0;
    }
  }
}
void solution(){
  cin >> V >> E;
  for(int i = 0; i < E; i++){
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i = 0 ; i < V; i++){
    check[i] = 1;
    dfs(i, 1);
    check[i] = 0;
  }
  cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
