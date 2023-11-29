#include <iostream>
#include <algorithm>
using namespace std;

int N; 
int arr[2000];
int ans;
void solution(){
  cin >> N;
  for (int i = 0; i < N ; i++){
    cin >> arr[i];
  }
  sort(arr, arr + N);

  for(int i = 0; i < N; i++){
    int p1 = 0, p2 = N-1, cur = arr[i];

    while(p1 < p2){
      if(p1 == i) p1++;
      if(p2 == i) p2--;
      if(p1 >= p2) break;
      
      int comb = arr[p1] + arr[p2];
      if(cur == comb){
        ans++;
        break;
      }
      if(cur > comb) p1++;
      else p2--;
    }
  }
  cout << ans << "\n";  
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
