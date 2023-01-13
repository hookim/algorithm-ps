#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, idx, i, j;
    long long p, absP,  min, li, lj;
    vector<long long> L;
    cin >> N;
    for(idx = 0; idx < N; idx++){
      cin >> p;
      L.push_back(p);
    }
    sort(L.begin(), L.end());
    
    i = 0, j = N-1;
    min = 1e10; // positive
    while(i < j){
      p = L[i] + L[j];
      absP = p < 0 ? -p : p;
      if(min > absP){
        li = L[i];
        lj = L[j];
        min = absP;
      }

      if(L[i] > 0 && L[j] > 0)
        j--;
      else if(L[i] < 0 && L[j] < 0)
        i++;
      else{
        if(p > 0)
          j--;
        else if(p < 0)
          i++;
        else
          break;
      }
    }

    cout << li << " " << lj << endl;

    return 0;
}
