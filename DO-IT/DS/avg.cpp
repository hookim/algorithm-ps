#include <iostream>

using namespace std;

int main(void){
    int N, max, t, sum, i;
    cin >> N;
    for (max = -1, sum = 0, i = 0; i < N; i++){
      cin >> t;
      if(t > max) max = t;
      sum += t;
    }
    cout << (double) 100 * sum / (max * N) << "\n";
    return 0;
}
