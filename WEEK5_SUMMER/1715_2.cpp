#include <queue>
#include <iostream>

using namespace std;

int main(void){
    int N;
    cin >> N;

    priority_queue <int, vector <int>, greater<int> > cards;
    
    for(int i = 0; i < N; i++){
        int k;
        scanf("%d", &k);
        cards.push(k);
    }
    int ans = 0;
    int min1, min2;

    while(true){
        min1 = cards.top();
        ans += min1;
        cards.pop();
        if(!cards.empty()){
            min2 = cards.top();
            ans += min2;
            cards.pop();
        }else{
            ans -= min1;
            break;
        }

        cards.push(min1 + min2);
    }

    printf("%d\n", ans);
    return 0;
}
