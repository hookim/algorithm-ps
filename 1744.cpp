#include <queue>
#include <cmath>
#include <iostream>

using namespace std;
const int MIN = -1001;

int main(void){
    priority_queue <int> positive;
    priority_queue <int> negAndZero;
    int N;
    cin >> N;
    for(int i = 0; i < N ; i++){
        int n;
        scanf("%d", &n);
        if(n > 0){
            positive.push(n);
        }else{
            negAndZero.push(-n);
        }
    }
    int temp = MIN;
    int ans = 0;
    while(!positive.empty()){
        if (temp == MIN){
            temp = positive.top();
            positive.pop();
        }else{
            int topVal = positive.top();
            positive.pop();
            if(temp * topVal > temp + topVal)
                ans += (temp * topVal);
            else
                ans += (temp + topVal);
            temp = MIN;
        }
    }
    if (temp != MIN)
        ans += temp;
    
    temp = MIN;
    while(!negAndZero.empty()){
        if (temp == MIN){
            temp = -negAndZero.top();
            negAndZero.pop();
        }else{
            int topVal = -negAndZero.top();
            negAndZero.pop();
            if(temp * topVal > temp + topVal)
                ans += (temp * topVal);
            else
                ans += (temp + topVal);
            temp = MIN;
        }
    }
    if (temp != MIN)
        ans += temp;

    cout << ans << endl;

    return 0;
}
