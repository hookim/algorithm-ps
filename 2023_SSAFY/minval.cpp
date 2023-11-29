#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, L, a;
int ans[5000000];

void solution(){
  priority_queue <pair <int , int>> pq;
  cin >> N >> L;
  for(int i = 1; i <= N ; i++){
    cin >> a;
    pq.push({-a, i});

    while(!pq.empty() && pq.top().second <= i - L){
      pq.pop();
    }
    ans[i-1] = -pq.top().first;
  }

  for(int i = 1; i <= N ; i++){
    cout << ans[i-1] << " ";
  }
  cout << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
