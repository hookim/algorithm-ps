#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {int a; int b;} M;
bool sortByB(const M &x, const M &y){return (x.b == y.b? x.a < y.a : x.b < y.b );}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, a, b, last_end, ans;
    vector<M> v;

    cin >> N;
    while(N--){
      cin >> a >> b;
      v.push_back({a, b});
    }
    sort(v.begin(), v.end(), sortByB);
    
    last_end = 0, ans = 0;
    for(auto m : v){
      if(last_end <= m.a){
        ans++;
        last_end = m.b;
      }
    }
    cout << ans << endl;

    return 0;
}
