#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, v, ans, a ,b;
    priority_queue <int> ne, po;

    cin >> N;
    while(N--){
      cin >> v;
      if(v > 0) po.push(v);
      else ne.push(-v);
    }
    ans = 0;
    while(po.size() > 1){
      a = po.top(); po.pop();
      b = po.top(); po.pop();
      if(a == 1 || b == 1)
        ans += (a + b);
      else 
        ans += (a * b);
    }
    while(ne.size() > 1){
      a = ne.top(); ne.pop();
      b = ne.top(); ne.pop();
      ans += (a * b);
    }
    while(!po.empty()){
      ans += po.top(); po.pop();
    }
    while(!ne.empty()){
      ans += (-ne.top()); ne.pop();
    }
    cout << ans << endl;
    
    return 0;
}
