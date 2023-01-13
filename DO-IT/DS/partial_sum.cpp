#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S, i ,j, t, idx, ans;
    long long A[100001], sum;

    cin >> N >> S;
    A[0] = 0;
    for(sum = 0, idx = 1; idx <= N; idx++){
      cin >> t;
      A[idx] = (A[idx-1] + t);
    } 

    i = 0, j =1;
    ans = 100001;
    while(j <= N){
      sum = A[j] - A[i];
      if(sum < S || i == j) 
        j++;
      else{
        if(ans > j - i)
          ans = j - i;
        i++;
      }
    }
    
    cout << (ans == 100001 ? 0 : ans) << endl;

    return 0;
}
