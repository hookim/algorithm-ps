#include <iostream>
#include <string>

using namespace std;

int main(void){
    int N ;
    cin >> N;
    int num = 665;
    while(N){
        num++;
        string s = to_string(num);
        int consec6 = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '6'){
                consec6++;
            }else{
                consec6 = 0;
            }
            if(consec6 == 3){
                break;
            }
        }
        if (consec6 == 3){
            N--;
        }
    }
    cout << num << endl; ;

    return 0;
}
