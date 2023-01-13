#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long T, N, M , t, idx, ni, nj, mi, mj, psumN, psumM, ans;
    long long psums_n[1001], psums_m[1001];

    cin >> T;
    
    cin >> N;
    for(psums_n[0] = 0, idx = 1; idx <= N; idx++){
      cin >> t;
      psums_n[idx] += t;
    }

    cin >> M;
    for(psums_m[0] = 0, idx = 1; idx <= M; idx++){
      cin >> t;
      psums_m[idx] += t;
    }

    ans = 0;
    ni = 0, nj = 1, mi = 0, mj = 1;
    while(nj <= N && mj <= M){
      psumN = psums_n[nj] - psums_n[ni];
      psumM = psums_m[mj] - psums_m[mi];
      if(psumN + psumM == T){
        ans++;
      }
      else if(psumN + psumM > T){
        
        nj++;
      }
      else{

      }
      
      

    }

    return 0;
}
