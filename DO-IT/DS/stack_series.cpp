#include <iostream>
#include <stack>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, t, i, idx, prev_top;
    stack <int> s;
    string ans = "";

    cin >> N;
    ans = "";
    for(prev_top = 0, i = 0 ; i < N ; i ++){
      cin >> t;
      if(t > prev_top){
        for (idx = prev_top + 1; idx <= t && idx <= N; idx++){
          s.push(idx);
          ans += "+\n";
        }
        prev_top = s.top();
        s.pop();
        ans += "-\n";
      }
      else{
        while(s.size() < 1 && s.top() > t){
          s.pop();
          ans += "-\n";
        }

        if(s.top() == t){
          s.pop();
          ans += "-\n";
        }
        else{
          cout << "NO" << endl;
          return 0;
        }
      }
    }

    cout << ans;
    return 0;
}
