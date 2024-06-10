#include <iostream>
#include <stack>

using namespace std;

int N, a;
stack<int> arr, ans, rightBigger;

int main (void){

    cin >> N;

    for(int i = 0 ; i < N ; i++){
        cin >> a;
        arr.push(a);
    }

    while(!arr.empty()){
        int v = arr.top();
        arr.pop();
        if(rightBigger.empty()){
            ans.push(-1);
        }
        else{
            while(!rightBigger.empty() && rightBigger.top() <= v){
                rightBigger.pop();
            }

            if(rightBigger.empty()){
                ans.push(-1);
            }
            else{
                ans.push(rightBigger.top());
            }
        }
        rightBigger.push(v);

    }

    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }

    cout << "\n";


    return 0;
}