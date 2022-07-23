#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int main(void){ 
    stack <pair <int, int> > s;
    int N, k;
    scanf("%d", &N);
    vector <int> ans(N);
    ans[N-1] = -1;
    for(int i = 0 ; i < N-1; i++){
        scanf("%d", &k);
        pair <int, int> PAIR;
        PAIR.first = k;
        PAIR.second = i;
        if (s.empty())
            s.push(PAIR);
        else{
            while(!s.empty()){
                if (s.top().first < k){
                    ans[s.top().second] = k;
                    s.pop();
                }
                else{
                    s.push(PAIR);
                    break;
                }
            }
            if (s.empty())
                s.push(PAIR);    
        }
    }
    scanf("%d", &k);
    while(!s.empty()){
        if(s.top().first < k)
            ans[s.top().second] = k;
        else
            ans[s.top().second] = -1;
        s.pop();
    }

    for(int i = 0; i < N; i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}
