#include <iostream>
#include <cstring>

using namespace std;

int N;
short valid[12] = {31, 28, 31, 30, 31, 30, 31 , 31, 30, 31, 30, 31};
string s;


void solution(){
  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> s;
    int m = stoi(s.substr(4,2));
    int d = stoi(s.substr(6,2));
    cout << "#" << i  << " ";
    if(valid[m-1] >= d && d > 0)
      cout << s.substr(0,4) << "/" << s.substr(4,2) << "/" << s.substr(6,2) << "\n";
    else
      cout << -1 << "\n";
    
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
