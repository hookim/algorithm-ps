#include <iostream>
#include <queue>

using namespace std;

class comparator{
public:
  bool operator()(const pair<int, int> a ,const pair<int, int> b){
    if(a.first != b.first)
      return a.first > b.first;
    return a.second > b.second;
  }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, i, t;
    priority_queue <pair <int, int>, vector<pair <int , int> >, comparator >pq;

    cin >> N;
    for(i = 0 ; i < N ; i++){
      cin >> t;
      if(t == 0){
        if(pq.empty()) cout << 0 << "\n";
        else {
          cout <<pq.top().second << "\n";
          pq.pop();
        }
      }
      else
        pq.push(make_pair(t < 0 ? -t : t ,t));
    }

    return 0;
}
