#include <iostream>
#include <cmath>

using namespace std;

int N;
bool isPrime(int x){
  for(int i = 2; i <= sqrt(x); i++)
    if(x % i == 0) return false;
  return true;
}

void dfs(int d, int num){
  if(N == d){
    printf("%d\n", num);
    return;
  }

  for(int i = 1; i <= 9; i += 2){
    if(isPrime(num * 10 + i))
      dfs(d+1, num * 10 + i);
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    
    if(N == 1) {
      printf("2\n3\n5\n7\n");
      return 0;
    }

    dfs(1, 2); dfs(1, 3); dfs(1, 5); dfs(1, 7);
    
    return 0;
}
