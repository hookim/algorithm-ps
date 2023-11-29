#include <iostream>

using namespace std;
int N;

int tsn(int n){
  int count = 0;
  while(n){
    int cur = n % 10;
    if(cur == 3 || cur == 6 || cur == 9) count++;
    n /= 10;
  }
  return count;
}

void solution(){
  cin >> N;
  for(int i = 1; i <= N; i++){
    int c = tsn(i);
    if(c){
      for(int j = 0; j < c; j++){
        cout << "-";
      }
      cout << " ";
    }
    else{
      cout << i << " ";
    }
  }
  cout << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
