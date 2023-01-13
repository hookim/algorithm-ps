#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long> sumA, sumB;
    vector<long long>::iterator lower, upper;
    long long a[1000], b[1000];
    int N, M, i, j;
    long long ans, sum, diff, T;

    cin >> T;

    cin >> N;
    for(i = 0; i < N; i++) cin >> a[i];
    
    cin >> M;
    for(i = 0; i < M; i++) cin >> b[i];
    
    for(i = 0; i < N; i++){
      sum = a[i];
      sumA.push_back(sum);
      for(j = i+1; j < N; j++){
        sum += a[j];
        sumA.push_back(sum);
      }
    }
    for(i = 0; i < M; i++){
      sum = b[i];
      sumB.push_back(sum);
      for(j = i+1; j < M; j++){
        sum += b[j];
        sumB.push_back(sum);
      }
    }

    sort(sumB.begin(), sumB.end());

    ans = 0;
    for(long long x : sumA){
      diff = T - x;
      upper = upper_bound(sumB.begin(), sumB.end(), diff);
      lower = lower_bound(sumB.begin(), sumB.end(), diff);
      ans += (upper-lower);
    }
    cout << ans << endl;

    return 0;
}
