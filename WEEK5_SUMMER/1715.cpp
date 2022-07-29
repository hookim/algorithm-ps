#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int N;
    cin >> N;
    vector <int> cards;
    for(int i = 0 ; i < N; i++){
        int n;
        scanf("%d", &n);
        cards.push_back(n);
    }

    sort(cards.begin(), cards.end());
    
    if(N ==1)
        printf("%d\n", cards[0]);
    else if(N == 2)
        printf("%d\n", cards[0] + cards[1]);
    else{
        int prevMin = cards[0] + cards[1];
        int ans = prevMin;
        for(int i = 2; i < N; i++){
            prevMin = prevMin + cards[i];
            ans += prevMin;
        }
        printf("%d\n", ans);
    }

    return 0;
}
