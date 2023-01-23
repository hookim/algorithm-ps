#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

queue <pair <int, int> > q;
vector<pair <int, int> > g[100000];
int visited[100000];
int maxL, node;

void bfs(int n){
  pair<int, int> cur;

  q.push(make_pair(n, 0));
  visited[n-1] = 1;
  while(!q.empty()){
    cur = q.front(); q.pop();
    if(cur.second > maxL){
      maxL = cur.second;
      node = cur.first; 
    }
    for(auto v : g[cur.first-1]){
      if(!visited[v.first-1]){
        visited[v.first-1] = 1;
        q.push(make_pair(v.first, cur.second + v.second));
      }
    }
  }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, a, b, i, vi;

    cin >> N;
    for(i = 0 ; i < N; i++){
      cin >> vi;
      cin >> a;
      while (a != -1){
        cin >> b;
        g[vi-1].push_back(make_pair(a, b)); 
        cin >> a;
      }
    }

    bfs(1);
    memset(visited, 0, N * sizeof(int));
    maxL = 0;
    bfs(node);
    cout << maxL << endl;

    return 0;
}
