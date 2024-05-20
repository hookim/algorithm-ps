#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, x, ans =10000;
vector<pair <int, int>> homes, chickenPlace;
bool picks[14];

int calcdist(){
  int ret = 0;
  for(auto home :homes){
    int temp = 10000;
    for(int i = 0; i < chickenPlace.size() ; i++){
      if(!picks[i])
        continue;  
      temp = min(temp, abs(home.first - chickenPlace[i].first) + abs(home.second - chickenPlace[i].second));  
    
    }
    ret += temp;
  }

  return ret;
}

void solve(int beg, int depth){
  if(depth == M){

    int ret = calcdist();
    ans = min(ans, ret);
  
    return ;
  }


  for(int i = beg; i < chickenPlace.size(); i++){
  
    picks[i] = true;
    solve(i+1, depth+1);
    picks[i] = false;

  }

}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        cin >> x;
        if(x == 1)
          homes.push_back({i, j});
        
        if(x == 2)
          chickenPlace.push_back({i, j});
      }
    }

    solve(0, 0);

    cout << ans << endl;

    return 0;
}
