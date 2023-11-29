#include <iostream>
#include <stack>

using namespace std;


int ser[1000000];
int N;
stack<int> ans, r;
void solution(){
  cin >> N;
  for(int i = 0 ; i < N ; i++){
    cin >> ser[i];
  }
  r.push(-1);
  for(int i = N-1; i >= 0 ; i--){
    if(ser[i] >= r.top()){
      while(!r.empty() && ser[i] >= r.top()){
        r.pop();
      }
      if(r.empty()) ans.push(-1);
      else ans.push(r.top());
    }
    else{
      ans.push(r.top());
    }
    r.push(ser[i]);
  }
  while(!ans.empty()){
    cout << ans.top() << " ";
    ans.pop();
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
