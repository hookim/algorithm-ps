#include <deque>
#include <iostream>

using namespace std;
int main(void){
    deque <int> dq;
    int N; 
    string cm;
    cin >> N;
    for(int i = 0; i < N ; i++){
        cin >> cm;
    
        if (cm.substr(0,4) == "push"){
            int k;
            cin >> k;
            if(cm.substr(5,1) == "f")
                dq.push_front(k);
            else
                dq.push_back(k);
        }

        else{
            int isEmpty = dq.empty();
            
            if(cm.substr(0, 3) == "pop"){
                if (isEmpty) 
                    cout << -1 <<endl;
                else if(cm.substr(4,1) == "f"){
                    cout << dq.front() << endl;
                    dq.pop_front();
                }else{
                    cout << dq.back() << endl;
                    dq.pop_back();
                }
            }

            else if(cm == "size"){
                cout << dq.size() << endl;
            }

            else if (cm == "empty"){
                cout << isEmpty << endl;
            }

            else{
                if (isEmpty) 
                    cout << -1 << endl;
                else if(cm == "front")
                    cout << dq.front() << endl; 
                else
                    cout << dq.back() << endl;
            }
        }
    }
    
    return 0;
}
