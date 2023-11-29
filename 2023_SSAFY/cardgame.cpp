#include <iostream>
#include <deque>

using namespace std;

int N, a;
deque<int> d;


void solution(){
  cin >> N;
  for(int i = 1; i <= N; i++){
    d.push_back(i);
  }
  while(d.size() > 1){
    d.pop_front();
    d.push_back(d.front());
    d.pop_front();
  }
  cout << d.front() << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
