#include <iostream>

using namespace std;

short ans[201];
short visited[201][201][201];
int A, B, C, e1;
short beenB4;

void pour(int a, int b, int c){

  if(a == 0) ans[c] = 1;
  if(visited[a][b][c]) return;  
  visited[a][b][c] = 1;


  if((e1 = min(a, B-b))) pour(a-e1, b+e1, c); 
  if((e1 = min(a, C-c))) pour(a-e1, b, c+e1);
  if((e1 = min(b, A-a))) pour(a+e1, b-e1, c);
  if((e1 = min(b, C-c))) pour(a, b-e1, c+e1);
  if((e1 = min(c, A-a))) pour(a+e1, b, c-e1);
  if((e1 = min(c, B-b))) pour(a, b+e1, c-e1);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B >> C;
    pour(0, 0, C);

    for(int i =0; i <= 200; i++){
      if(ans[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}
