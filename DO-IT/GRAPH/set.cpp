#include <iostream>

using namespace std;

int S[1000001];
int find(int k){
  if(S[k] == k)
    return k;
  return (S[k] = find(S[k]));
}
void unio(int a, int b){
  S[find(b)] = find(a);
} 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, o,a,b;
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
      S[i] = i;
    while(M--){
      cin >> o >> a >> b;
      if(o == 0)
        unio(a, b);
      else{
        if(find(a) == find(b)) cout << "YES\n";
        else cout << "NO\n";  
      }
    }
    return 0;
}
