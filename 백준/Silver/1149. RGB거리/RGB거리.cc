#include <iostream>
#include <algorithm>

using namespace std;

/*
dp입력 받으면서 최솟값 갱신한다
dp[3][0] 은 3번째 집을 빨간색으로 칠할 때의 총 최솟값
dp[i][0] += max(dp[i][1], dp[i][2]) 
*/

int N;
int dp[1001][3];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++){
      cin >> dp[i][0] >> dp[i][1] >> dp[i][2];

      dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
      dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
      dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
    }

    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]) << "\n";

    return 0;
}
