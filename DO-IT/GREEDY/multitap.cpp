#include <iostream>

using namespace std;

int N, K, tot, cur, midx, mval, ans, j ,k;
int isIn[101], streams[100];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < K; i++)
      cin >> streams[i];
    
    for(int i = 0; i < K; i++){
      cur = streams[i];
      if(!isIn[cur]){
        if(tot < N){
          isIn[cur] = 1;
          tot++;
        }else{
          midx = -1;
          mval = -1;
          for(j = 1; j <= 100; j++){
            if(isIn[j]){
              for(k = i+1; k < K; k++){
                if(streams[k] == j)
                  break;
              }
              if(mval < k - i){
                mval = k - i;
                midx = j;
              }
            }
          }
          isIn[midx] = 0;
          isIn[cur] = 1;
          ans++;
        }
      }
    }
    cout << ans << endl;


    return 0;
}
