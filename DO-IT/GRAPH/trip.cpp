#include <iostream>

using namespace std;

int orders[201];
short visited[201];
short g[201][201];
int N, M, a, i, n, d, idx; 
string s;

void dfs(int n){
  visited[n] = 1;
  for(int i = 1; i <= N; i++){
    if(g[n][i] && !visited[i]) dfs(i);
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        cin >> g[i][j];
      }
    }
    getchar();
    getline(cin, s);
    for(i = 0, n = 0, d = 100, idx = 0 ; i < s.size(); i++){
      if(!('0' <= s[i] && '9' >= s[i]) && n){
        orders[idx++] = (d == 0 ? n : n / (d * 10));
        n = 0; d = 100;
      }
      else{
        n += d * (s[i] - '0');
        d = (int) d / 10;
      }
    }
    orders[idx++] = (d == 0 ? n : n / (d * 10));
    dfs(orders[0]);
    
    for(int i = 0; i < idx; i++){
      if(!visited[orders[i]]) {
        cout << "NO" << endl;
        return 0;
      }
    }
    cout << "YES" << endl;

    return 0;
}
