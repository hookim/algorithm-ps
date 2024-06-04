#include <iostream>
#include <vector> 
#include <algorithm>
#include <stack>

using namespace std;

int N, ans, a;

vector<int> arr1, arr2;

void solve(){
    int cnt = 0;
    for(int i = 1; i < arr1.size(); i+=2){
        ans += (arr1[i] * arr1[i-1]);
        cnt +=2;
    }    
    if(arr1.size() != cnt){
        ans += -(arr1[arr1.size()-1]);
    }
    
    cnt = 0;
    for(int i = 1; i < arr2.size(); i+=2){
        ans += (arr2[i] * arr2[i-1]);
        cnt +=2;
    }    
    if(arr2.size() != cnt){
        ans += arr2[arr2.size()-1];
    }
}

int main(void){
    cin >> N;

    for(int i = 0 ; i < N ; i++){
        cin >> a;

        if(a == 1){
            ans++;
        }
        else if(a > 0){
            arr1.push_back(-a);
        }
        else if(a <= 0){
            arr2.push_back(a);
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    solve();

    cout << ans << endl;

    return 0;
}

