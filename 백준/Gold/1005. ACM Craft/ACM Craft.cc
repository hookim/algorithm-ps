#include <iostream>
#include <vector>
#include <map>
#define MAX 100001

using namespace std;

map<int, bool> points[1001];
int T, N, K, W, a, b;
long long times[1001], memo[1001];

long long solve(int v){
    long long maxTime = -1;

    for(auto it = points[v].begin(); it != points[v].end(); it++){
        if(!points[v][it->first])
            continue;
        if(memo[it->first] != times[it->first]){
            maxTime = max(maxTime, memo[it->first]);
        }
        else{
            maxTime = max(maxTime, solve(it->first));
        }
        points[v][it->first] = false;
    }

    if(maxTime == -1){
        return (long long)times[v];
    }
    else{
        memo[v] = maxTime + times[v];
        return (long long) maxTime + times[v];
    }
}

int main (void){
    cin >> T;

    for(int t = 0; t < T; t++){
        cin >> N >> K;
        for(int i = 1; i <= N; i++){
            points[i].clear();
        }
        for(int i = 1; i <= N ; i++){
            cin >> times[i];
            memo[i] = times[i];
        }
        for(int i = 0 ; i < K; i++){
            cin >> a >> b;
            points[b][a] = true;
        }
        cin >> W;
        cout << solve(W) << "\n";
    }


    return 0;
}