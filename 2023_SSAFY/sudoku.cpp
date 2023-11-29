#include <iostream>
#include <cstring>

using namespace std;

int T;
short puzzle[9][9];

void getPuzzle(){
  for(int i =0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      cin >> puzzle[i][j];
    }
  }
}

int verify(){
  short check[2][9];
  int a, b;
  for(int i =0; i < 9; i++){
    memset(check, 0, sizeof(short) * 18);
    for(int j =0; j < 9; j++){
      a = puzzle[i][j];
      b = puzzle[j][i];
      if(check[0][a-1] || check[1][b-1]) return 0;
      check[0][a-1] = 1;
      check[1][b-1] = 1;
    }
  }
  short check2[9];
  for(int i= 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      int x = i * 3;
      int y = j * 3;
      memset(check2, 0, sizeof(short) * 9);
      while(y < j * 3 + 3){
        if(check2[puzzle[x][y]-1]){
          return 0;
        }
        check2[puzzle[x++][y]-1] = 1;
        if(x == i*3 +3) {
          x = i * 3;
          y++;
        }
      }
    }
  }
  return 1;
}

void solution(){
  cin >> T;
  for(int t = 1 ; t <= T; t++){
    getPuzzle();
    cout << "#" << t << " " << verify() << "\n";
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
