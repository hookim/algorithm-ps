#include <iostream>

using namespace std;
int N, K, ans;
int coins[10];

void solution(){
  cin >> N >> K;
  for(int i =0 ; i < N; i++){
    cin >> coins[i];
  }
  for(int i=N-1; i>=0; i--){
    int c = coins[i];
    if(K / c){
      ans += (K / c);
      K %= c;
    }
    if(K == 0) break;
  }
  cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
