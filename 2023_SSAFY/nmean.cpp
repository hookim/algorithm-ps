#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int T; 
int arr[10];

void solution(){
  cin >> T;
  for(int i = 0; i < T; i++){
    int mi = 10000, ma = 0, su = 0;
    for(int j = 0; j < 10; j++){
      cin >> arr[j];
      mi = min(mi, arr[j]);
      ma = max(ma, arr[j]);
      su += arr[j];
    }
    cout << "#" << i+1 << " " << round((double)(su-mi-ma) / 8) << "\n";
    memset(arr, 0, 10);
  }

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
