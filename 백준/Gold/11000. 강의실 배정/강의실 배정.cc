#include <iostream>
#include <queue>
#include <vector> 
#include <algorithm>

using namespace std;

int N, a, b;
priority_queue<int> pq; 
vector<pair <int,int>> arr;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}

void solve(){
    pq.push(-arr[0].second);

    for(int i = 1; i < arr.size(); i++){
        
        if(-pq.top() <= arr[i].first){
            pq.pop();
        }
        pq.push(-arr[i].second);
    }
}

int main(void){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end(), cmp);
    solve();
    cout << pq.size() << endl;

    return 0;
}

