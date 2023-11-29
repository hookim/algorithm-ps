#include <iostream>

using namespace std;

int scores[10][101];
int T, t, a;

void solution(){
  cin >> T;
  for(int i = 0 ; i < T ; i++){
    cin >> t;
    for(int j = 0; j < 1000; j++){
      cin >> a;
      scores[t-1][a]++;
    }
    int max_frq = 0 , ans = 0;
    for(int j = 0; j <= 100; j++){
      if(max_frq <= scores[t-1][j]){
        ans = j;
        max_frq = scores[t-1][j];
      }
    }
    cout << "#" << t << " " << ans << "\n";
  }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
