#include <iostream>
#include <vector> 
#include <algorithm>

#define MAX 1000000000

using namespace std;

int N, S, a, ans = MAX;
vector<int> arr;

void solve(){
    int beg = 0, end = 1;
    while(end <= N){
        int ssum = arr[end] - arr[beg-1];
        if(ssum >= S){
            ans = min(ans, end-beg+1);
            beg++;

            if(beg > end){
                end++;
            }
        }
        else {
            end++;
        }
    }
}

int main(void){

    cin >> N >> S;

    arr.push_back(0);
    int tsum = 0;
    for(int i = 0; i < N; i++){
        cin >> a;
        tsum += a;
        arr.push_back(tsum);
    }

    solve();

    if(ans == MAX){
        cout << 0 << endl;
    }
    else{
        cout << ans << endl;
    }

    return 0;
}

