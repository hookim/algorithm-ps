#include <iostream>
#include <cmath>

using namespace std;

char buf[51];
char c;
int ans, idx, num, ne, d, flag; 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fgets(buf, 51, stdin);
    while((c = buf[idx++])){
      num = 0; d = 4;
      while(c >= '0' && c <= '9'){
        num += (c - '0') * (int)pow(10, d--); 
        c = buf[idx++];
      }
      if(d >= 0) num /= (int)pow(10, d+1);
      
      if(flag) ne += num;
      else ans += num;

      if(c == '-' || c != '+'){
        flag = 1;
        ans -= ne;
        ne = 0;
      }

    }
    cout << ans << endl;

    return 0;
}
