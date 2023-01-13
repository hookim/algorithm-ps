#include <iostream>

using namespace std;

int psums[1025][1025];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q, sum, t,i,j,a,b,c,d;

    cin >> N >> Q;
    for(i = 1; i <= N; i++){
      for(j = 1; j <= N; j++){
        cin >> t;
        sum = t + psums[i][j-1] + psums[i-1][j] - psums[i-1][j-1];
        psums[i][j] = sum;
      } 
    }
    for(i = 1; i <= Q; i++){
      cin >> a >> b >> c >> d;
      cout << psums[c][d] - psums[a-1][d] - psums[c][b-1] + psums[a-1][b-1] << "\n";
    }
    return 0;
}
