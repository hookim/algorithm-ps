#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int V, E, a, b, ans;

vector<int> g[1000];
stack<int> s; 
short check[1000];

void solution(){
  cin >> V >> E;
  for(int i = 0; i < E; i++){
    cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }
  for(int i = 0; i < V; i++){
    if(check[i]) continue;
    ans++;
    s.push(i);
    while(!s.empty()){
      int cur = s.top();
      check[cur] = 1;
      s.pop();
      for(auto it =  g[cur].begin(); it < g[cur].end(); it++){
        if(!check[*it]){
          s.push(*it);
        }
      }
    }
  }
  cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
