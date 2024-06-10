#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

int N, K;
int cnt[MAX];
// class Compare{public: bool operator()(const pair<int, int> &a, const pair<int, int> &b){return a.second < b.second;}};

void solve(){
    // priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    queue<pair<int, int>> q;
    cnt[N] = 0;
    q.push({N, 0});
    
    while(!q.empty()){
        int cur = q.front().first;
        int curT = q.front().second;
        q.pop();

        if(cur * 2 < MAX && cnt[cur * 2] > curT){
            cnt[cur * 2] = curT;
            q.push({cur*2, curT});
        }
        if(cur -1 >= 0 && cnt[cur - 1] > curT+1){
            cnt[cur - 1] = curT + 1;
            q.push({cur-1, curT + 1});
        }
        if(cur + 1 < MAX && cnt[cur + 1] > curT+1){
            cnt[cur + 1] = curT+1;
            q.push({cur+1, curT + 1});
        }

    }
}

int main (void){
    cin >> N >> K;

    for(int i = 0; i < MAX; i++){
        cnt[i] = MAX;
    }

    solve();

    cout << cnt[K] << "\n";

    return 0;
}