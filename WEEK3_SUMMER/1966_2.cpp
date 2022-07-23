#include <queue>
#include <iostream>

using namespace std;

int main(void){
    int T;
    scanf("%d", &T);
    for(int i = 0 ; i < T; i++){
        int K, pos;
        scanf("%d %d", &K, &pos);
        queue <int> q;
        int rec[10] = {0};
        int v;
         
        for(int j = 0; j < K; j++){
            scanf("%d", &v);
            q.push(v);
            rec[v] += 1;
        }   
        int ans = 0;    
        while(true){
            int notYet = 0;
            for(int k  = q.front() + 1; k <= 9; k++){
                if(rec[k]){
                    q.push(q.front());
                    q.pop();
                    notYet =1;
                    break;
                }
            }
            if(!notYet){
                ans += 1;
                rec[q.front()] -= 1;
                q.pop();
                if (pos == 0){
                    printf("%d\n", ans);
                    break;
                }
            }
            pos = (pos + q.size() - 1) % q.size();
        }
    }
    return 0;
}
