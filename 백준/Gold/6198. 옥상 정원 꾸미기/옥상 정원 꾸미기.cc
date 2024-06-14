#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector <int> arr;
stack<pair<int, long long>> s;
long long N, a, ans;

int main (void){
    cin >> N;
    for(int i = 0; i< N; i++){
        cin >> a;
        arr.push_back(a);
    }

    for(int i = arr.size()-1; i >= 0; i--){
        if(s.empty()){
            s.push({arr[i], 0});
        }
        else{
            long long temp = 0;
            while(!s.empty() && s.top().first < arr[i]){
                ans += s.top().second;
                temp += (s.top().second + 1);
                s.pop();
            }
            s.push({arr[i], temp});
        }
    }

    while(!s.empty()){
        ans += s.top().second;
        s.pop();
    }

    cout << ans << "\n";

    return 0;
}