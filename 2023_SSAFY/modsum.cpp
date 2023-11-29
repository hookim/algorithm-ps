#include <iostream>

using namespace std;


int idx[1000];
int N, M;
long long res, a, b;

void solution(){
  cin >> N >> M;
  for(int i = 0; i < N ; i++){
    cin >> a;
    idx[b = (a + b) % M]++;
  }
  res = idx[0];
  for(int i = 0; i < M; i++){
    if(idx[i] >= 2) res += (idx[i] * (idx[i] - 1) / 2);
  }
  cout << res << "\n";
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
