#include <iostream>

using namespace std;

int N;
int idx0 = 1, idx1 =1;
long long cur = 1, temp;
int ans;

void solution(){
  cin >> N;
  while (idx1 <= N){
    temp = cur;
    if(temp == N) ans++;
    if(temp >= N) cur -= (idx0++);
    if(temp <= N) cur += (++idx1);
  }
  cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
