#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, G, i, j, sum, ans;
    int stuffs[15000];
    cin >> N >> G;
    for(i = 0; i < N; i++){
      cin >> stuffs[i];
    }

    if(G > 200000){
      cout << 0 << endl;
      return 0;
    }

    sort(stuffs, stuffs+N);
    
    i = 0;
    j = N-1;
    ans = 0;
    sum = 0;
    while(i != j){
      sum = stuffs[i] + stuffs[j];
      if(sum == G) ans++;
      if(sum >= G) j--;
      else i++;
    }

    cout << ans << endl;
    return 0;
}
