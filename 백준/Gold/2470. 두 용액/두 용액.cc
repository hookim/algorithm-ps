#include <iostream>
#include <vector> 
#include <algorithm>
#include <map>

#define MAX 2000000001

using namespace std;

long long N, a, ansA, ansB, ans = MAX;
vector<int> arr;

void solve(){
    int beg = 0, end = N-1;

    while(beg < end){
        long long v = arr[beg] + arr[end];

        if(abs(v) < ans){
            ans = abs(v);
            ansA = beg;
            ansB = end; 
        }

        if(v == 0){
            ansA = beg;
            ansB = end;
            return;
        }
        if(v > 0){
            end--;
        }
        if(v < 0){
            beg++;
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

    cout << arr[ansA] << " " << arr[ansB] << "\n";

    return 0;
}

