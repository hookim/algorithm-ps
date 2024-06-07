#include <iostream>
#include <vector> 
#include <algorithm>

#define MAX 1000000000

using namespace std;

int ans, N, C, a;
vector<int> pos;

void solve(){
    int b = 1, e = MAX;

    while(b <= e){
        int mid = (b + e) / 2;
        int router =1, prevIdx = 0, minDist = MAX;
        for(int i =1; i < N; i++){
            int dist = pos[i] - pos[prevIdx];

            if(dist >= mid){
                minDist = min(minDist, dist);
                router++;
                prevIdx = i;
            }
        }

        if(router >= C){
            b= mid+1;
            ans = max(ans, minDist);
        }
        if(router < C){
            e=mid-1;
        }
    }
}

int main(void){    
    cin >> N >> C;

    for(int i = 0; i < N; i++){
        cin >> a;
        pos.push_back(a);
    }

    sort(pos.begin(), pos.end());

    solve();

    cout << ans << "\n";
}

