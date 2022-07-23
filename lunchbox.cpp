#include <queue>
#include <iostream>

using namespace std;

int main(void){
    int C;
    scanf("%d", &C);
    for(int cases = 0 ; cases < C; cases++){
        int N;
        scanf("%d", &N);
        queue <int> warm, eat;
        for(int i = 0 ; i < N; i++){
            int k;
            scanf("%d", &k);
            warm.push(k);
        }
        for(int i = 0 ; i < N; i++){
            int k;
            scanf("%d", &k);
            eat.push(k);
        }
        int newBegin = 0, newEnd = 0, end = 0;
         
        while(!eat.empty()){
            int maxIdx = 0, maxVal = eat.front();
            for(int i = 0; i < eat.size(); i++){
                if (eat.front() > maxVal){
                    maxIdx = i;
                    maxVal = eat.front();
                }
                eat.push(eat.front());
                eat.pop();
            }
            for(int i = 0 ; i < maxIdx; i++){
                eat.push(eat.front());
                warm.push(warm.front());
                eat.pop();
                warm.pop();
            }
            newBegin += warm.front();
            warm.pop();
            newEnd = newBegin + eat.front();
            eat.pop();
            if(newEnd > end){
                end = newEnd;
            }
        }

        printf("%d\n", end);


    }

    return 0;
}
