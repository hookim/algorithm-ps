#include <iostream>
#include <algorithm>

using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long nums[2000];
    int N, idx, i , j;
    long long ans, sum, cur;

    cin >> N;
    for(idx = 0; idx < N; idx++){
      cin >> nums[idx];
    }
    sort(nums, nums+N);

    for (ans = 0, idx = 0 ; idx < N; idx++){
      i = 0;
      j = N-1;
      cur = nums[idx];
      if(j == idx) j--;
      if(i == idx) i++;
      while(i < j){
        sum = nums[i] + nums[j]; 
        if(sum == cur){
          ans++;
          break;
        }
        if(sum > cur) j--;
        else i++;
        
        if(j == idx) j--;
        if(i == idx) i++;
      } 
    }

    cout << ans << endl;

    return 0;
}
