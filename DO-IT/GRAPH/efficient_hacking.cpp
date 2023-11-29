#include <iostream>
#include <vector>

using namespace std;

vector<int> g[10001];
short visited[10001];
int ans[10001];
int N, M, a, b, k, mk;

void dfs(int x, int& k){
  visited[x] = 1; 
  k++;
  for(auto v: g[x]){
    if(!visited[v])
      dfs(v,k);
  }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    while(M--){
      cin >> a >> b;
      g[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
      k = 0; 
      memset(visited, 0, sizeof(short) * (N + 1));
      dfs(i, k);
      ans[i] = k;
      if(mk < k) mk = k;
    }
    for(int i = 1; i <= N; i++)
      if(ans[i] == mk) cout << i << " ";
    cout << endl;
    
    return 0;
}
