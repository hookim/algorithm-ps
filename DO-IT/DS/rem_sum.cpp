#include <iostream>
#include <vector>

using namespace std;

long long rem[1000];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, i, t;
    long long ans, sum;
    vector<int> psums;

    cin >> N >> M;
    for(sum = 0, i = 0; i < N; i++){
      cin >> t;
      sum += t;
      sum %= M;
      psums.push_back(sum);  
    }

    for(ans = 0, i = 0; i < N; i++){
      if(psums[i] == 0) 
        ans++;
      rem[psums[i]]++;
    }

    for(i = 0 ; i < M; i++){
      if(rem[i] >= 2)
        ans += (rem[i] * (rem[i] - 1) / 2);
    }

    cout << ans << "\n";
    
    return 0;
}
