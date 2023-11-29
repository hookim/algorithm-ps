#include <iostream>
#include <queue>

using namespace std;

vector<int> g[300001];
short visited[300001];
short ans[3000001];
int N, M, K, X, a, b, cur, d, found;
queue<pair<int , int > > Q; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K >> X;
    for(int m = 0; m < M ; m++){
      cin >> a >> b;
      g[a].push_back(b);
    }
    visited[X] = 1;
    Q.push({X, 0});
    while(!Q.empty()){
      cur = Q.front().first; d = Q.front().second; Q.pop();
      if(d == K){
        found = 1;
        ans[cur] = 1;
        continue;
      }
      for(auto v : g[cur]){
        if(!visited[v]){
          visited[v] = 1;
          Q.push({v, d+1});
        }
      }
    }

    if(!found) cout << -1 << endl;
    else{
      for(int i = 1; i <= N; i++)
        if(ans[i]) cout << i << "\n";
    }
    return 0;
}
