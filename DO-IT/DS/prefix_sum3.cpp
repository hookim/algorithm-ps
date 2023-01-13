#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long psums[100001];
    long long N, S, t, sum, psum, idx, i, j, ans;

    cin >> N >> S;
    for(sum = 0, idx = 1; idx <= N; idx++){
      cin >> t;
      psums[idx] = (sum += t);
    }

    i = 0;
    j = 1;
    ans = 100001;
    while(i <= N && j <= N){
      psum = psums[j] - psums[i];
      if(psum == S){
        if(j-i < ans) ans = j-i;
      }
      if(psum >= S) i++;
      if(psum <= S) j++;
    }

    cout << (ans == 100001 ? 0 : ans) << endl;

    return 0;
}
