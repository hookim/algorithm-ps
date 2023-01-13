#include <iostream>
#include <deque>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L , i, t;
    pair <int, int> x;
    deque <pair <int, int> > window; 

    cin >> N >> L;
    
    for(i = 0; i < N; i++){
      cin >> t;
      x.first = t;
      x.second= i;

      while(!window.empty()){
        if(x.first <= window.back().first)
          window.pop_back();
        else
          break;
      }

      window.push_back(x);

      while(!window.empty()){
        if(window.front().second <= i - L)
          window.pop_front();
        else
          break;
      }
      cout << window.front().first << " ";
    }
    cout << endl;

    return 0;
}
