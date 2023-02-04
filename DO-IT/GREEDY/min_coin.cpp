#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K, v, n, ans;
    priority_queue <int> pq;
    cin >> N >> K;
    while(N--){
      cin >> v;
      pq.push(v);
    }
    ans = 0;
    while(!pq.empty()){
      v = pq.top(); pq.pop();
      n = (int)(K / v);
      ans += n;
      K -= (v * n);
    }
    cout << ans << endl;
    
    return 0;
}
