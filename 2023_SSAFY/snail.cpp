#include <iostream>

using namespace std;

int T, a;
int arr[10][10];

void solution(){
  cin >> T;
  for(int t = 0; t < T; t++){
    cin >> a;
    bool v = false;
    int x = 1, y = 1, i=0, j=0, n = 1, dlock = 0;
    while(true){
      if(dlock >= 2) break;

      if((i >= a || i < 0)){
        v = false;
        i -= x;
        x = -x;
        dlock++;
      }
      else if(j >= a || j < 0){
        v = true;
        j -= y;
        y = -y;
        dlock++;
      }
      else if(arr[i][j]){
        dlock++;
        if(v){
          v = false;
          i -= x;
          x = -x;
        }
        else {
          v = true;
          j -= y;
          y = -y;
        }
      }
      else{
        arr[i][j] = n++;
        dlock = 0;
      }
      if(v) i += x;
      else j += y;

    }

    cout << "#" << t+1 << "\n";
    for(int i = 0; i < a; i++){
      for(int j = 0; j < a; j++){
        cout << arr[i][j] << " ";
        arr[i][j] = 0;
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
