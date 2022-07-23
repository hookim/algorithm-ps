#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main(void){
    int N;
    cin >> N;
    queue <int> q;
    for (int i =0 ; i < N; i++){
        char cm[6] = {0};
        scanf("%s", cm);
        if (!strcmp(cm ,"push") ){
            int k;
            scanf("%d", &k);
            q.push(k);
        }
        else{
            int isEmpty = q.empty();
            if (cm[0] == 'p'){
                if (isEmpty)
                    printf("%d\n", -1);
                else{
                    printf("%d\n", q.front());
                    q.pop(); 
                }
            }
            else if (cm[0] == 's'){
                printf("%d\n", q.size());
            }
            else if (cm[0] == 'e'){
                printf("%d\n", isEmpty);
            }
            else if (cm[0] == 'f'){
                if(isEmpty)
                    printf("%d\n", -1);
                else 
                    printf("%d\n", q.front());
            }
            else if (cm[0] == 'b') {
                if(isEmpty)
                    printf("%d\n", -1);
                else
                    printf("%d\n", q.back());
            }
        }
    }
    return 0;
}
