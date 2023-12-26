#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char alp[15];

void gen(string pw, int idx){
  if(pw.length() == L){
    int v = 0, c =0;
    for(int i = 0; i < pw.length(); i++){
      if(pw[i] =='a' || pw[i] =='e' || pw[i] =='i' || pw[i] =='o' || pw[i] =='u') v++;
      else c ++;
    }
    if(v >= 1 && c >=2) cout << pw << "\n";
    return;
  }
  if(pw.length() + (C - 1 - idx) < L) return;
  for(int i = idx + 1; i < C; i++){
    gen(pw + alp[i], i);
  }

}

void solution(){
  cin >> L >> C;
  for(int i = 0; i < C; i++){
    cin >> alp[i];
  }
  sort(alp, alp + C);
  gen("", -1);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
