#include <iostream>

using namespace std;

int T, N;

int solve(int N){
    int ans = 0;
    for(int i  = 0; i <= N / 3; i++){
        ans += ((N - i * 3) / 2 + 1);  
    }

    return ans;
}

int main(void){
    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> N;
        cout << solve(N) << "\n";
    }

    return 0;
}

