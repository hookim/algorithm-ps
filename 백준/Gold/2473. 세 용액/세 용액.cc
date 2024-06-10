#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>
#define MAX 3000000001L

using namespace std;

int N, a;
long long idealV = MAX;
vector<long long> arr;
long long ans[3]; 

void solve(){
    for(int i = 0; i < N; i++){

        int b = 0, e = N-1;

        while(b < e){
            if(b == i){
                b++;
                continue;
            }
            if(e == i){
                e--;
                continue;
            }

            long long v = arr[b] + arr[e] + arr[i];
            if(abs(v) < idealV){
                idealV = abs(v); 
                ans[0] = arr[i];
                ans[1] = arr[b];
                ans[2] = arr[e];
            }

            if(v < 0){
                b++;
            }
            if(v > 0){
                e--;
            }
            if(v == 0){
                return;
            }
        }
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

    sort(ans, ans + 2);

    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
 
    return 0;
}

