#include <iostream>
#include <stack>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    stack <int>s;
    for (int i =0 ; i < n; i++){
        string cm;
        cin >> cm;
        if (cm != "push"){
            int isEmpty = s.empty();
            if(cm == "pop"){
                if(isEmpty)
                    cout << -1 << endl;
                else{
                    cout << s.top() << endl;
                    s.pop();
                }
            }else if(cm == "size"){
                cout << s.size() << endl;            
            }else if(cm == "top"){
                if (!isEmpty)
                    cout << s.top() << endl;
                else
                    cout << -1 << endl;
            }else if (cm == "empty"){
                cout << (int)s.empty() << endl;
            }
        }else{
            int k;
            cin >> k;
            s.push(k);
        }

    }

    return 0;
}
