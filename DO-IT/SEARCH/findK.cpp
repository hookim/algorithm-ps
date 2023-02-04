#include <iostream>

using namespace std;

long long N, K, b, e, m, cnt, ans;
// 1 2 2 3 3 4 4 4 5 5 6 6 8 8 9 10 10 ...
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    b = 1;
    e = N * N;
    while(b <= e){ 
      m = (long long)(b + e) / 2;
      cnt = 0;
      for(int i = 1; i <= N; i++)
        cnt += min(N, (long long)m / i);
      if(cnt >= K) {
        ans = m;
        e = m - 1;
      }
      else b = m + 1;
    }
    cout << ans << endl;

    return 0;
}
