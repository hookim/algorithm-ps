#include <iostream>
#include <deque>

using namespace std;

int T, N, M, tmp, found, nomore;
char c;
deque <char> hist;
string mapper[10] = {"0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011" };
int codeCheck (){
  string s ="";
  cout <<"this" << s << endl;
  for(auto it = hist.begin(); it != hist.end(); it++){
    s += *it;
  }
  for(int i = 0; i < 10; i++){
    if(s.compare(mapper[i]) == 0){
      return i;
    }
  }
  return -1;
}

void solution(){
  cin >> T;
  int ans;
  for(int t = 1; t <= T; t++){
    cin >> N >> M;
    ans = 0, nomore = 0, found = 0;
    for(int n = 0; n < N; n++ ){
      for(int m = 0; m < M; m++){
        cin >> c;
        if(nomore) continue;
        hist.push_back(c);
        if(hist.size() == 7)
          hist.pop_front();
        if(c == '1' && (tmp = codeCheck()) >= 0){
          ans += tmp;
          found++;
          while(!hist.empty()){
            hist.pop_front();
          }
        }
      }
      if(found > 0 && found < 8) {
        ans = -1;
        nomore = 1;
      }
      if(found == 8)
        nomore =1;
      found = 0;
    }

    cout << "#" << t << " " << ans << "\n";
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
