#include <iostream>
#include <stack>

using namespace std;

string ans = "";
stack<int> s;
int N, newVal = 1;
int target;

void solution(){
  cin >> N;
  for(int i = 0 ; i < N ; i++){
    cin >> target;
    if (ans == "NO") continue;
    if(newVal <= target){
      while(newVal <= target){
        s.push(newVal++);
        ans += "+\n";
      }
      s.pop();
      ans += "-\n";
    }
    else{
      if(s.top() == target){
        s.pop();
        ans += "-\n";
      }
      else
        ans = "NO"; 
    }
  } 
  cout << ans << endl;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
