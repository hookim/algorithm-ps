#include <iostream>

using namespace std;

int fib[41][2];
int T, N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fib[0][0] = 1;
    fib[1][1] = 1;
    for(int i =2; i <= 40; i++){
      fib[i][0] = fib[i-1][0] + fib[i-2][0];
      fib[i][1] = fib[i-1][1] + fib[i-2][1];
    }


    cin >> T;
    for(int i = 0; i < T; i++){
      cin >> N;
      cout << fib[N][0] << " " << fib[N][1] << "\n";
    }

    return 0;
}
