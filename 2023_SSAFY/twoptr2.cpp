#include <iostream>
// #include <algorithm>
using namespace std;

int arr[15000];
int N, M, idx1, idx2;
int ans = 0;

void solution(){
  cin >> N >> M;
  for(int i =0 ; i < N; i++){
    cin >> arr[i];
  }
  sort(arr, arr + N);

  idx2 = N-1;
  while(idx1 < idx2){
    int cur = arr[idx1] + arr[idx2];
    if(M >= cur) idx1++;
    if(M <= cur) idx2--;
    if(M == cur) ans++;
  }
  cout << ans << "\n";  
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
