#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int  N, a, ans;
vector<int> arr;

int searchAndReturn(int v, int avoid){
    int b = 0, e = N-1;

    while(b < e){
        if(b == avoid){
            b++;
            continue;
        }
        if(e == avoid){
            e--;
            continue;
        }

        if(v == arr[b] + arr[e]){
            return 1;
        }

        if(v < arr[b] + arr[e]){
            e--;
        }

        if(v > arr[b] + arr[e]){
            b++;
        }
    }

    return 0;
}

void solve(){
    
    for(int i = 0; i < N; i++){
        ans += searchAndReturn(arr[i], i);
    }

}

int main(void){    
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    solve();
    cout << ans << endl;

    return 0;
}

