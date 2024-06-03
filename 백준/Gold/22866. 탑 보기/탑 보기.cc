#include <iostream>
#include <vector> 
#include <algorithm>
#include <stack>

using namespace std;

vector<int> arr;
int N, a;
int ans[100000], buildings[100000];

void solve(){
    stack<pair<int, int>> s1, s2;

    for(int i = 0; i < N; i++){
        while(!s1.empty() && arr[i] >= s1.top().second){
            s1.pop();
        }
        ans[i] = s1.size();
        if(!s1.empty()){
            buildings[i] = s1.top().first;
        }

        s1.push({i+1, arr[i]});
    }

    for(int i = N-1; i >= 0 ; i--){
        while(!s2.empty() && arr[i] >= s2.top().second){
            s2.pop();
        }
        ans[i] += s2.size();

        if(!s2.empty()){
            if(buildings[i] && i+1  - buildings[i] > abs(s2.top().first -(i+1) )){
                buildings[i] = s2.top().first;
            }
            if(buildings[i] && i - buildings[i] == s2.top().first - i){
                buildings[i] = min(buildings[i], s2.top().first);
            } 
            if(buildings[i] == 0){
                buildings[i] = s2.top().first;
            }
            
        }

        s2.push({i+1, arr[i]});
    }
}

int main(void){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a;
        arr.push_back(a);
    }

    solve();

    for(int i = 0; i < N; i++){
        if(ans[i]){
            cout << ans[i] << " " << buildings[i] << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }


    return 0;
}
