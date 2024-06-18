#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Compare{
public: bool operator() (const pair<int, int> &a, const pair<int, int> &b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    else{
        return a.first < b.first;
    }
}
};

int N, K, cnt;
char c;
vector<char> arr;
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 0 ; i < N; i++){
        cin >> c;
        arr.push_back(c);

        while(cnt < K && !pq.empty() && c > pq.top().second){
            arr[pq.top().first] = 0;
            pq.pop();
            cnt++;
        }
        pq.push({i, c});
    }
    while(cnt < K){
        arr[pq.top().first] = 0;
        pq.pop();
        cnt++;
    }

    for(int i = 0 ; i < N; i++){
        if(arr[i] == 0) continue;
        cout << arr[i];
    }
    cout << endl;
    

}