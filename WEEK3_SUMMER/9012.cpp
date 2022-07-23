// Parenthesis
#include <iostream>
#include <stack>

using namespace std;

int main(void){
    int N;
    scanf("%d\n", &N);
    for (int i = 0; i < N ; i++){
        stack <char> s;
        char c = getchar();
        int stopFurther = 0;
        while (c != '\n'){
            if (c == '('){
                s.push(c);
            }else if (c == ')'){
                if (!s.empty())
                    s.pop();
                else {
                    printf("NO\n");
                    while(c != '\n'){
                        c = getchar();
                    }
                    stopFurther = 1;
                    break;
                }
            }
            c = getchar(); 
        }
        if (stopFurther) continue;
        
        if(!s.empty())
            printf("NO\n");
        else
            printf("YES\n");   
    }
    
    return 0;
}
