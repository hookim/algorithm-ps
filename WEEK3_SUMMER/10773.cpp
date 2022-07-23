// Zero That Out
#include <iostream>
#include <stack>

using namespace std;

int main(void){
    int N;
    cin >> N;
    int k;
    stack <int> s;
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &k);
        if (k == 0)
            s.pop();
        else
            s.push(k);
    }
    int sum = 0;
    while (!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout << sum << endl;

    return 0;
}
