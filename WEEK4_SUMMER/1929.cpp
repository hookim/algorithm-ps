#include<vector>
#include <iostream>

using namespace std;

int main(void){
    int M, N;
    cin >> M >> N;

    vector<int> pn;
    pn.push_back(2);

    for (int i = 2 ; i < N; i++){
        int isPrime = 1;
        for(int j = 0; j < pn.size(); j++){
            if((i+1) % pn[j] == 0){
               isPrime = 0;
               break; 
            }
            if (pn[j] > (int)(i+1) / 2){
                break;
            }
        }
        if(isPrime)
            pn.push_back(i+1);
        
    }
    
    for(int i = 0; i < pn.size(); i++){
        if(pn[i] >= M)
            printf("%d\n", pn[i]);
    }

    return 0;
}
