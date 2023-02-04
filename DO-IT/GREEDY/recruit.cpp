#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int> > cand[20];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N, a, b, ans, req;
    cin >> T;
    while(T--){
      cin >> N;
      while(N--){
        cin >> a >> b;
        cand[20-T].push_back({a, b});
      }
      sort(cand[20-T].begin(), cand[20-T].end());
      ans = 0, req = 100e3+1;
      for(auto v : cand[20-T]){
        if(req > v.second){
          ans++;
          req = v.second;
        }
      }
      cout << ans << endl;  
    }

    return 0;
}
