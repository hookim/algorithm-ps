#include <iostream>

using namespace std;

//메모리 초과
int main(void){ 
    int T;
    scanf("%d", &T);
    for(int i = 0 ; i < T; i++){
        int K, pos;
        scanf("%d %d", &K, &pos);
        int* q = new int(K);
        int v;
        for(int j = 0; j < K; j++){
            scanf("%d", &v);
            q[j] = v;
        }

        int front = 0, cur = 0, ans = 0; 
        int notYet =0;
        while(1004){
            cur = (front + 1) % K;
            notYet =0;
            for(int i = 0; i < K-1; i++){
                if (q[front] < q[cur]){
                    notYet = 1;    
                    break;
                }
                cur = (cur + 1) % K;
            }  
            if(!notYet){
                q[front] = -1;
                ans++;
                if(front == pos){
                    printf("%d\n", ans);
                    break;
                }
            }
            front = (front + 1) % K;
        }
        delete(q);
    }

    return 0;
}
