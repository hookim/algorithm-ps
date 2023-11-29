#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N, a;
class compare{
public:
	bool operator() (const pair<int, int> a, const pair<int, int> b){
		if(a.first > b.first) return true;
    if(a.first < b.first) return false;
    if(a.second > b.second) return true;
    else return false;
	}
};

priority_queue < pair<int, int>, vector< pair<int, int> >, compare > pq;

void solution(){  
  cin >> N;
  for(int i =0 ; i < N; i++){
    cin >> a;
    if(a) pq.push({abs(a), a});
    else {
      if(!pq.empty()){
        cout << pq.top().second  << "\n"; 
        pq.pop();
      }else{
        cout << 0 << "\n";
      }
    
    }
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
