#include <iostream>

using namespace std;
int arr[100001];
int N, M, ans, b, e, m, _sum;

int canMakeIt(int blueRay){
  int idx = 0;
  for(int i = 0; i < M; i ++){
    int cur = 0;
    while(idx <= N){
      cur += arr[idx++];
      if(cur > blueRay){
        idx--;
        break;
      }
    }
  }
  if(idx <= N) return 0;
  else return 1;
}
void solution(){
  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    cin >> arr[i];
    _sum += arr[i];
  }
  b = 1; 
  e = _sum;
  while(b <= e){
    m = (b + e) / 2;
    int res = canMakeIt(m);
    if(res){
      e = m-1;
      ans = m;
    }
    else
      b = m+1;
  }
  cout << ans << "\n";

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
