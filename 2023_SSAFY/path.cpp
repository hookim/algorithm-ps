#include <iostream>
#include <queue>

using namespace std;

char path[100][100], c;
int N, M;
queue<pair <pair <int, int> , int>> q;
pair<int, int> dir[4] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};

void solution(){
  cin >> N >> M;
  for(int i = 0 ; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> c;
      path[i][j] = c - '0';
    }
  }  
  q.push({{0,0}, 1});
  path[0][0] = -1;

  while(!q.empty()){
    auto coord = q.front().first;
    auto dist = q.front().second;
    q.pop();
    if(coord.first == N-1 && coord.second == M-1){
      cout << dist << "\n";
      return;
    }

    for(int i = 0; i < 4; i++){
      int newX = coord.first + dir[i].first;
      int newY = coord.second + dir[i].second; 
      if(path[newX][newY] == 1 && newX >= 0 && newY >= 0 && newX < N && newY < M){
        path[newX][newY] = -1;
        q.push({{newX, newY}, dist+1});
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
