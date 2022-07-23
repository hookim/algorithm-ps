#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int main(void){
    int N; 
    cin >> N;

    vector <int> h;
    for(int i = 0 ; i < N ; i++){
        int k ;
        scanf("%d", &k);
        h.push_back(k);
    }
    stack < pair<int, int> > s;
    long long ans = 0;
    for(int i = N-1; i >= 0; i--){
        pair <int, int> p;
        p.first = h[i];
        p.second = 0;
        
        while(!s.empty()){
            if(s.top().first < h[i]){
                p.second += (s.top().second + 1);
                ans += s.top().second;
                s.pop();
            }else
                break;
        }
        
        s.push(p);
    }

    if (!s.empty()){
        while(!s.empty()){    
            ans += s.top().second;
            s.pop();
        }
    }

    cout << ans << endl;
    return 0;
}
