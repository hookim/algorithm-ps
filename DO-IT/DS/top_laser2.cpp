#include <iostream>
#include <stack>

using namespace std;

int ans[500000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, idx, t;
    stack <pair <int, int> > a;

    cin >> N;
    for(idx = 1; idx <= N; idx++){
      cin >> t;
      while(!a.empty() && a.top().first < t)
        a.pop();
      if(!a.empty())
        ans[idx-1] = a.top().second;
      a.push(make_pair(t, idx));
    }
    for(idx = 0; idx < N; idx++)
      cout << ans[idx] << " ";
    cout << endl;
    
    return 0;
}
