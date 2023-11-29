#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

bool isPrime(int n){
  for(int i = 2; i < (int)n/2 ; i++){
    if(n % i == 0) return false;
  }
  return true;
}
void dfs(int n, int d){
  if(!isPrime(n)) return;
  if(d == N){
    v.push_back(n);
    return;
  }
  for(int i = 0 ; i < 5; i++){
    dfs(n*10+(i*2+1), d+1);
  }

}
void solution(){
  cin >> N;
  dfs(2, 1);
  for(int i = 1; i < 5; i++){
    dfs(i*2+1, 1);
  }
  sort(v.begin(), v.end());
  for(const auto &i : v){
    cout << i << "\n";
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
