#include <iostream>
#include <algorithm>

bool res;
int N, T, target;
int arr[100000];


using namespace std;

void bsearch(int a, int b){
  if(a > b) {
    res = false;
    return;
  }
  int mid = (a+b) / 2;
  if(arr[mid] == target){
    res = true;
    return;
  }
  else if(arr[mid] > target)
    bsearch(a, mid-1);
  else 
    bsearch(mid+1, b);

}

void solution(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }
  sort(arr, arr+N);
  cin >> T;
  for(int i = 0; i < T; i++){
    cin >> target;
    bsearch(0, N-1);
    cout << res << "\n";
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
