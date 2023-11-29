#include <iostream>

using namespace std;

int N, M, a, x1, y1, x2, y2;
int sum[1025][1025];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
      for(int j = 1 ; j <= N ; j++){
        cin >> sum[i][j];
        sum[i][j] += (sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]);
      }
    }
    for(int i = 0 ; i < M; i++){
      cin >> x1 >> y1 >> x2 >> y2;
      cout << (sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] ) << "\n";
    }

    return 0;
}
