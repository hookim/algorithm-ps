//종만북 짝이 맞지 않는 괄호문제

#include<iostream>
#include<stack>

using namespace std;

int main(void){
    int T;
    cin >> T;
    for(int i =0 ; i < T ;i++){
        string str;
        cin >> str;
        stack<char> s;
        for(int j = 0; j < str.length(); j++){
            if(str[j] == '{' || str[j] == '(' || str[j] == '[' ) s.push(str[j]);
            else{
                
                 
                }
            }
        }



    }




