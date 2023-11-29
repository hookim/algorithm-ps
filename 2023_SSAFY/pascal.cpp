#include <iostream>

using namespace std;

int T, N;
int arr[10][10];

int pascal(int i , int j){
  if(arr[i][j]) return arr[i][j];
  if(j < 0 || j > i) return 0;

  int res = pascal(i-1, j-1) + pascal(i-1, j);
  arr[i][j] = res;
  return res;
}

void solution(){
  arr[0][0] = 1;
  for(int i = 0; i < 10; i++){
    pascal(9, i);
  }

  cin >> T;
  for(int t = 1; t <= T; t++){
    cin >> N;
    cout << "#" << t << "\n";
    for(int i = 0; i < N; i++){
      for(int j = 0; j <= i; j++){
        cout << arr[i][j] << " ";
      }
      cout << "\n";
    }
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
