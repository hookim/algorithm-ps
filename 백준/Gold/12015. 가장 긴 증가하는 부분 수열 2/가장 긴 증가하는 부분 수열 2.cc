#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

long long N, a;
vector<int> arr, lis;

void searchAndReplace(int x){
    int b = 0, e = lis.size(), m = (b+e)/2;
    while(b < e){
        m = b + (e-b) / 2;

        if(lis[m] < x){
            b = m+1;
        }
        else{
            e = m;
        }

    }
    lis[e] = x;
} 

void solve(){
    lis.push_back(arr[0]);

    for(int i = 1; i < N; i++){
        if(lis[lis.size()-1] < arr[i]){
            lis.push_back(arr[i]);
        }
        else{
            searchAndReplace(arr[i]);
        }
    }
}

int main(void){    
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a;
        arr.push_back(a);
    }
    
    solve();
    cout << lis.size() << endl;

    return 0;
}

