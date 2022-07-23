#include <iostream>

using namespace std;

int main(void){
    char s[100001] = {0};
    char prev = 0, cur;
    int idx =0;
    scanf("%s",s);
    int level = 0, ans = 0;
    cur = s[0];
    while(cur != 0){
        if (cur == '('){
            level++;
        }
        else if (prev == '(' && cur == ')'){
            level --;
            ans += (level);
        }
        else if (cur == ')'){
            level--;
            ans += 1;
        }

        prev = cur;
        cur = s[++idx];
    }
    printf("%d\n", ans);

    return 0;
}
 