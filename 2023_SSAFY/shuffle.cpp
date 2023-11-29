#include <iostream>
#include <string>

using namespace std;

int T, N, n, ans, i;
string S;
bool check[10][1000000][10];

void shuffle(string s, int n){
  if(n == N){
    if(stoi(s) > ans)
      ans = stoi(s);
    return;
  }

  if(check[i][stoi(s)][n])
    return;

  check[i][stoi(s)][n] = true;
  
  for(int j = 0; j < S.size(); j++){
    for(int k = 0; k < S.size(); k++){
      if(j == k) continue;
      string newS = s;
      newS[j] = s[k];
      newS[k] = s[j];
      shuffle(newS, n+1);
    }
  }
}

void solution(){
  cin >> T;
  for(i =0 ; i < T; i++){
    cin >> S >> N;
    shuffle(S, 0);
    cout << "#" << i+1 << " " << ans << "\n";
    ans = 0;
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
