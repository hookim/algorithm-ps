#include <iostream>

using namespace std;
char arr[8][8];
int N;
void solution(){
  for(int t = 1; t <= 10; t++){
    cin >> N;
    for(int i = 0 ; i < 8 ; i++){
      for(int j = 0; j < 8; j++){
        cin >> arr[i][j];
      }
    }
    int ans = 0;
    int xv, yv, xh, yh;
    for(int i = 0; i < 8; i++){
      int isV = 1, isH = 1;
      for(int j = 0; j < 8; j++){
        if(N%2){
          

        }
        else{

        }

      }
    }
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
