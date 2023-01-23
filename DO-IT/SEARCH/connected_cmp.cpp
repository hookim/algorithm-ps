#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int visited[1000];
void dfs(vector<vector <int> > g, int i){
  int cur;
  stack <int> s;
  vector<int>::iterator it;

  s.push(i);
  while(!s.empty()){
    cur = s.top();
    s.pop();
    if(!visited[cur-1]){
      for(it = g[cur-1].begin() ; it != g[cur-1].end(); it++)
        s.push(*it);
      visited[cur-1] = 1;
    }
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E , a, b, idx, ans;
    vector<vector <int> > g;

    cin >> V >> E;
    for(idx = 0; idx < V; idx++){
      vector <int> x;
      g.push_back(x);
    }
    
    for (idx = 0; idx < E; idx++){
      cin >> a >> b;
      g[a-1].push_back(b);
      g[b-1].push_back(a);
    }

    for(ans = 0, idx= 1; idx <= V; idx++){
      if(!visited[idx-1]){
        dfs(g, idx);
        ans++;
      }
    }

    cout << ans << endl;;
    return 0;
}
