#include <iostream>
#include <stack>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack <pair <int, int> > a, b; 
    int ans[500000];
    int N, t, idx;
    
    cin >> N;
    for(idx = 1; idx <= N; idx++){
      cin >> t;
      a.push(make_pair(t, idx));
    }

    b.push(a.top());
    b.pop();

    while(!a.empty()){
      while(!b.empty() && a.top().first >= b.top().first){
        ans[b.top().second - 1] = a.top().second;
        b.pop();
      }

      b.push(a.top());
      a.pop();
    }

    while(!b.empty()){
      ans[b.top().second - 1] = 0;
      b.pop();
    }

    for(idx = 0; idx < N; idx++){
      cout << ans[idx] << " ";
    }
    cout << endl;

    return 0;
}
