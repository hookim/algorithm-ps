#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
    int N, K;
    cin >> N >> K;
    priority_queue < pair <int, int> > jewls;
    for(int i = 0 ; i < N; i++){
        int w, v;
        scanf("%d %d", &w, &v);
        jewls.push(make_pair(v, w));
    }
    priority_queue <int> bags;
    for(int i = 0; i < K; i++){
        int c;
        scanf("%d" , &c);
        bags.push(c);
    }
    int maxCap = bags.top();
    
    int ans = 0;
    while(!bags.empty()){
        if(bags.top() >= jewls.top().second){
            ans += jewls.top().first;
            bags.pop();
        }
        jewls.pop();
    }
    cout << ans << endl;

    return 0;
}