#include <iostream>

using namespace std;

int D, arr[100];

void solution(){
  for(int t = 1; t <= 10; t++){
    cin >> D;
    int mi = 0, ma = 0;
    int maVal = 0, miVal = 100;
    for(int i = 0; i < 100; i++){
      cin >> arr[i];
      if(maVal < arr[i]) {
        maVal = arr[i];
        ma = i;
      }
      if(miVal > arr[i]){
        miVal = arr[i];
        mi = i;
      } 
    }
    
    for(int d = 0; d < D; d++){
      arr[ma]--;
      arr[mi]++;

      for(int i = 0; i < 100; i++){
        if(arr[mi] > arr[i]) mi = i;
        if(arr[ma] < arr[i]) ma = i;
      }
      if(arr[ma] - arr[mi] <= 1) break;
    }
    cout << "#" << t << " " << arr[ma] - arr[mi] << "\n";
  }

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
