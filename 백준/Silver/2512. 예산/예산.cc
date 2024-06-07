#include <iostream>
#include <vector> 
#include <algorithm>
#include <map>

#define MAX 1000000001

using namespace std;

int N, a, target, ans;
vector<int> budget;

void solve(){
    int b = 1; int e = target;

    while(b <= e){
        int m = (b + e) / 2;
        
        int temp = 0;
        int maxB = 0;

        for(int i = 0; i < N; i++){
            if(temp > target){
                temp = MAX;
                break;
            }
            if(budget[i] > m){
                temp += m;
                maxB = max(maxB, m);
            }
            else{
                temp+= budget[i];
                maxB = max(maxB, budget[i]);
            }
        }

        if(temp > target){
            e = m - 1;
        }
        else{
            ans = max(ans, maxB);
            b = m + 1;
        }
    }
}

int main(void){    
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a;
        budget.push_back(a);
    }
    cin >> target;

    solve();

    cout << ans << "\n";
}

