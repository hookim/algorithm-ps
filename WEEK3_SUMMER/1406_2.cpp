#include <stack>
#include <iostream>

using namespace std;

int main(void){
    string str;
    int N;
    cin >> str;
    cin >> N;

    stack <char> left, right;
    for(int i =0 ; i< str.size() ; i++){
        left.push(str[i]);
    }

    char cm, c;
    for(int i =0 ; i < N; i++){
        cin >> cm;
        if(cm == 'L'){
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }else if(cm == 'D'){
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        }else if (cm == 'B'){
            if(!left.empty())
                left.pop();
        }else if (cm =='P'){
            cin >> c;
            left.push(c);
        }
    }
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        cout << right.top();
        right.pop();
    }

    return 0;
}
