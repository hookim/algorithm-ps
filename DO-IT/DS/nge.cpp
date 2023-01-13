#include <iostream>
#include <stack>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, t, idx;
    stack <int> left, right ,ans;
    right.push(0);

    cin >> N;
    for(idx = 0; idx < N; idx++){
      cin >> t;
      left.push(t);
    }

    while(!left.empty()){
      while(!right.empty() && (right.top() <= left.top()))
        right.pop();
      if(right.empty())
        ans.push(-1);
      else
        ans.push(right.top());
      
      right.push(left.top());
      left.pop();
    }

    for(idx = 0 ; idx < N; idx++){
      cout << ans.top() << " ";
      ans.pop();
    }
    cout << endl;

    return 0;
}
