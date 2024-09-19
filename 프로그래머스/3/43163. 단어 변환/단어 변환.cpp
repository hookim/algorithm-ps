#include <string>
#include <vector>
#include <map> 
#include <queue>

using namespace std;

int strDiff(const string x, const string y){
    int l = 0, ret = 0;
    while(l < x.length()){
        int d = (x[l] - y[l]) ? 1 : 0;
        ret += (d * d);
        l++;
    }
    return ret;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    queue<pair<string, int>> q;
    map<string, bool> visited;
    q.push({begin, 0});

    while(!q.empty()){
        string cur = q.front().first;
        int curStep = q.front().second;
        
        visited[cur] = true;
        q.pop();
        if(cur == target){
            answer = curStep;
            break;
        }
        
        
        for(auto it = words.begin(); it != words.end(); it++){
            if(visited[*it]) continue;
            if(strDiff(*it, cur) != 1) continue;
            
            visited[*it] = true;
            
            q.push({*it, curStep+1});
        }
    }
    
    return answer;
}