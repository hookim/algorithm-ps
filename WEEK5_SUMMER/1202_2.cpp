#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
    int N, K;
    cin >> N >> K;
    vector < pair <int, int> > jewls;
    for(int i = 0 ; i < N; i++){
        int w, v;
        scanf("%d %d", &w, &v);
        jewls.push_back(make_pair(w, v));
    }
    vector <int> bags;
    for(int i = 0; i < K; i++){
        int c;
        scanf("%d" , &c);
        bags.push_back(c);
    }
    sort(jewls.begin(), jewls.end());
    sort(bags.begin(), bags.end());
    
    priority_queue <int> pq;
    long long ans = 0;
    int idx =0;
    for(auto it = bags.begin(); it != bags.end(); it++){
        while(*it >= jewls[idx].first && idx < N){
            pq.push(jewls[idx++].second);
        }
        
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        
    }
    
    cout << ans << endl;

    return 0;
}
