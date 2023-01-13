#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, i, j, sum, ans;
    cin >> N;

    i = 1;
    j = 1;
    ans = 0;
    while(i <= N && j <= N){
      sum = (i + j) * (j - i + 1) / 2;
      if(sum == N) ans++;
      if (sum >= N) i++;
      else j++;
    }
    
    cout << ans << "\n";

    return 0;
}
