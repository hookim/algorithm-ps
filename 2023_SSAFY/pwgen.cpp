#include <iostream>
#include <deque>

using namespace std;

int T, a;

deque<int> dq;

void solution(){
  while(1){
    cin >> T;
    int isFinal = 1;
    for(int i = 0; i < 8; i++){
      cin >> a;
      dq.push_back(a);
      if(a >= 10) isFinal = 0;
    }
    
    while(1){
      int isDone = 0;
      for(int i = 1; i <= 5; i++){
        a = dq.front() - i;
        dq.pop_front();
        if(a <= 0){
          isDone = 1;
          i = 6;
          a = 0;
        }      
        dq.push_back(a);
      }
      if(isDone) break;
    }

    cout << "#" << T << " ";
    while(!dq.empty()){
      cout << dq.front() << " ";
      dq.pop_front();
    }

    if(isFinal) break;
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
