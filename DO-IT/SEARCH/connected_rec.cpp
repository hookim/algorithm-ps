#include <iostream>
#include <vector>

using namespace std;

vector<int> g[1000];
int visited[1000];

void dfs(int idx){
  if(visited[idx-1])
    return;
  visited[idx-1] = 1;
  for(auto i : g[idx-1])
    dfs(i);
  
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int V, E, a, b, idx, ans;
    cin >> V >> E;

    for(idx = 0; idx < E; idx++){
      cin >> a >> b;
      g[a-1].push_back(b);
      g[b-1].push_back(a);
    }

    for(ans = 0, idx = 1; idx <= V; idx++){
      if(!visited[idx-1]){
        dfs(idx);
        ans++;
      }
    }
    cout << ans << endl;
    return 0;
}
