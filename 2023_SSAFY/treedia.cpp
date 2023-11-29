#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair <int, int> > g[100000];
queue<pair <int, int> > q;
int N, idx, a , b, max_node, dist;
short check1[100000];

void max_bfs(int i, int mark){
  q.push({i, 0});
  check1[i] = mark; 
  while(!q.empty()){
    int cur_node = q.front().first;
    int cur_dist = q.front().second;
    q.pop();
    if(dist < cur_dist){
      max_node = cur_node;
      dist = cur_dist;
    }
    for(auto n : g[cur_node]){
      if(check1[n.first] != mark){
        check1[n.first] = mark;
        q.push({n.first, n.second + cur_dist});
      }
    }

  }
}

void solution(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> idx;
    cin >> a;
    while(a != -1){
      cin >> b;
      g[idx-1].push_back({a-1, b});
      cin >> a;
    }
  }
  max_bfs(0, 1);
  max_bfs(max_node, 2);
  cout << dist << "\n";
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
