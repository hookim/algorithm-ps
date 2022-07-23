#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(void){
    stack <int> s;
    queue <char> ans;

    int N, k ,last = 1, isFail = 0;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        scanf("%d", &k);
        for(int j= last; j <= k ; j++){
            s.push(j);
            ans.push('+');
            last++;
        }

        if (k == s.top()){
            s.pop();
            ans.push('-');
        }else {
            isFail =1;
            cout << "NO" << endl;
            break;
        }
    }

    if (!isFail){
        while(!ans.empty()){
            printf("%c\n",ans.front());
            ans.pop();
        }
    }

    return 0;
}
