#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<int, int> info;
int R, C;
bool check[500 * 500];
int dR[] = {0 ,1, -1, 0};
int dC[] = {1, 0, 0, -1};

void bfs(vector<vector<int>> &land, int r, int c, int idx){
    int s = 0;
    queue<pair<int, int>> q;
    s++;
    land[r][c] = idx;
    q.push({r, c});
    
    while(!q.empty()){
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();
        
        for(int d=  0; d < 4; d++){
            int nextR = curR + dR[d];
            int nextC = curC + dC[d];
            
            if(nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
            if(land[nextR][nextC] <= 0) continue;
            
            land[nextR][nextC] = idx;
            s++;
            q.push({nextR, nextC});
        }
    }
    info[idx] = s;
}

int drill(vector<vector<int>> &land, int c){
    memset(check, false, sizeof(check));
    int v, ret = 0;
    for(int i = 0 ; i < R; i++){
        if((v = land[i][c]) < 0){
            if(check[-v]) continue;
            check[-v] = true;
            ret += info[v];
        }
    }
    
    return ret;
    
}

int solve(vector<vector<int>> &land){
    R = land.size();
    C = land[0].size();
    
    int landidx = -1; 
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(land[i][j] <= 0) continue;
            bfs(land, i, j, landidx--);
        }
    }
    int x =  0;
    for(int i = 0 ; i < C; i++){
        x = max(x ,drill(land, i));    
    }
    return x;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    answer = solve(land);

    return answer;
}