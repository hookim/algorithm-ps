#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>
#define MAX 1000000001

using namespace std;

int  N, M, a, s, e, b, w, idealWeight;
vector<pair<int, int>> graph[100001];
bool visited[100001];

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    return a.second > b.second;
}

bool bfs(int minimum){
     queue<int>q;

    for(auto v : graph[s]){
        if(!visited[v.first] && v.second >= minimum){
            visited[v.first] = true;
            q.push(v.first);
        }
    }

    while(!q.empty()){
        int curV = q.front();
        q.pop();

        if(curV == e){
            return true;
        }

        for(auto v : graph[curV]){
            if(visited[v.first] || v.second < minimum){
                continue;
            }

            visited[v.first] = true;
            q.push(v.first);
        }
    }

    return false;
}

void solve(){
    int low = 1, high = idealWeight;

    while(low <= high){
        int m = low + (high - low) / 2;
        
        for(int i = 0; i <= N; i++){
            visited[i] = false;
        }

        if(bfs(m)){
            low = m+1;
        }
        else{
            high =  m-1;
        }
    }
    cout << high << endl;
   
}

int main(void){    
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});

        idealWeight = max(idealWeight, w);
    }
    cin >> s >> e;

    for(int i = 1 ; i <= N; i++){
        sort(graph[i].begin(), graph[i].end(), cmp);
    }
    solve();

    return 0;
}

