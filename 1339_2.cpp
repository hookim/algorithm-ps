#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int main(void){
    int N;
    cin >> N;
    vector <int> weights(26);
    for(int i =0 ; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            weights[s[j] -'A'] += -(int) pow(10, s.size()-j-1);
        }
    }
    sort(weights.begin(), weights.end());
    int n = 9;
    int ans = 0;
    for(int i =0 ; i < 26; i++){
        if(weights[i])
            ans += (-weights[i] * (n--));
    }
    cout << ans << endl;

    return 0;
}
