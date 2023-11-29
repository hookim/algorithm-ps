#include <iostream>

using namespace std;

int N, M, a, b;

void basicArray() {
  int sum[100001];

  cin >> N >> M;
  sum[0] = 0;
  for(int i = 1; i <= N; i++){
    cin >> a;
    sum[i] = sum[i-1] + a;
  }
  while(M--){
    cin >> a >> b;
    cout << sum[b] - sum[a-1] << "\n";
  }
}
void dynamicArray() {
  cin >> N >> M;

  int * sum = new int[N];
  sum[0] = 0;
  for(int i = 1; i <= N; i++){
    cin >> a;
    sum[i] = sum[i-1] + a;
  }
  while(M--){
    cin >> a >> b;
    cout << sum[b] - sum[a-1] << "\n";
  }
}

#include<vector>
void vectorArray(){
  cin >> N >> M;

  vector<int> sum;
  sum.push_back(0);
  for(int i = 1; i <= N; i++){
    cin >> a;
    sum.at(i) = (sum.at(i-1) + a);
  }
  while(M--){
    cin >> a >> b;
    cout << sum.at(b) - sum.at(a-1) << "\n";
  }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // basicArray();
    // dynamicArray();
    vectorArray();

    return 0;
}
