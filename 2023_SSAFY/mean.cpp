#include <iostream>
#include <cmath>

using namespace std;

int T, a;

void solution(){
  cin >> T;
  for(int t = 1; t <= T; t++){
    int ans = 0;
    for(int i = 0; i < 10; i++){
      cin >> a;
      ans += a;
    }
    cout << "#" << t << " " << round((double) ans / 10) << "\n";
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
