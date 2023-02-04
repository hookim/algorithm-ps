#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N , K, m, v;
    long long ans;
    vector<pair <int, int> > jewl;
    vector<int> bags;
    priority_queue<int> pq;
    cin>> N >> K;
    while(N--){
      cin >> m >> v;
      jewl.push_back({m, v});
    }
    while(K--){
      cin >> m;
      bags.push_back(m);
    }
    sort(jewl.begin(), jewl.end());
    sort(bags.begin(), bags.end());

    auto it = jewl.begin();
    ans = 0;
    for(auto v :bags){
      while(it != jewl.end() && (*it).first <= v){
        pq.push((*it).second);
        it++;
      }
      if(!pq.empty()){
        ans += pq.top();
        pq.pop();
      }
    }

    cout << ans << endl;
    return 0;
}
