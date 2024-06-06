#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int N, ans, ssum, a;
vector<int> arr;

void solve(){
    int beg= 0, end=0, dist = arr[beg];
    while(beg < N){
        int diff = 2 * dist - ssum;
        ans = max(ans, min(dist, ssum-dist));
        
        if(diff > 0){
            dist -= arr[beg];
            beg++;
        }

        if(diff < 0){
            end = (end + 1) % N;
            dist += arr[end];
        }

        if(diff == 0){
            return;
        }
    }

}

int main(void){    
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a;
        arr.push_back(a);
        ssum += a;
    }

    solve();
    cout << ans << endl;

    return 0;
}

