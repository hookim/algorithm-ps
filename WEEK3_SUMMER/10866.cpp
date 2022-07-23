#include <deque>
#include <iostream>

using namespace std;
int main(void){
    deque <int> dq;
    int N; 
    char cm[10];  
    scanf("%d", &N);
    for(int i = 0; i < N ; i++){
        scanf("%s", cm);

        if (cm[1] == 'u'){
            int k;
            scanf("%d", &k);
            if(cm[5] == 'f')
                dq.push_front(k);
            else
                dq.push_back(k);
        }

        else{
            int isEmpty = dq.empty();
            
            if(cm[0] == 'p'){
                if (isEmpty) 
                    printf("%d\n", -1);
                else if(cm[4] == 'f'){
                    printf("%d\n", dq.front());
                    dq.pop_front();
                }else{
                    printf("%d\n", dq.back());
                    dq.pop_back();
                }
            }

            else if(cm[0] == 's'){
                printf("%d\n", dq.size());
            }

            else if (cm[0] == 'e'){
                printf("%d\n", isEmpty);
            }

            else{
                if(isEmpty) 
                    printf("%d\n", -1);
                else if(cm[0] == 'f')
                    printf("%d\n", dq.front());
                else
                    printf("%d\n", dq.back());
            }
        }
    }
    
    return 0;
}
