#include <iostream>

using namespace std;


int N , M;
short serial[8];

void backtracking(int m, short serial[]){
  if(m == M){
    for(int i = 0; i < M; i++){
      cout << serial[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i = 1; i <= N; i++){
    bool c = true;
    for(int j = 0; j < m; j++){
      if(serial[j] == i) {
        c = false;
        break;
      }
    }
    if(c){
      serial[m] = i;
      backtracking(m+1, serial);
      serial[m] = 0;
    } 
  }
}

void solution(){
  cin >> N >> M;
  backtracking(0, serial);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
