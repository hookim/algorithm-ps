#include <iostream>

using namespace std;

int N, res;
char a;
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N ; i ++){
      cin >> a;
      res += (a - '0');
    }
    cout << res << endl;
    return 0;
}
