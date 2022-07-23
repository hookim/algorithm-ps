#include <iostream>
using namespace std;

int main(){
    int N, M, max =0;
    cin >> N >> M;
    int cards[N];
    
    for(int i = 0 ; i < N; i ++){
        cin >> cards[i];
    }
    for(int i = 0; i < N ; i++ ){
        if(cards[i] >= M) continue;
        for(int j = 0; j < N; j++){
            if(cards[i] + cards[j] >= M || i == j) continue;
            for(int k = 0; k < N; k++){
                if(i == k || j == k) continue;
                int cardV = cards[i] + cards[j] + cards[k];
                if(max < cardV && cardV <= M) 
                    max = cardV;                
            }
        }
    }
    cout<< max<<endl;

    return 0;

}
