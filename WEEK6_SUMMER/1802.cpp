#include <iostream>
using namespace std;
int count = 0;
int size = 1;

bool can_i_fold(string& s, int begin, int end){
    
}

int main(void){
    int N;
    cin >> N;
    string s;
    for(int i = 0; i < N ; i++){
        cin >> s;
        if(can_i_fold(s, 0, s.size()-1))
            printf("YES\n");
        else
            printf("NO\n");
    }
   
    return 0;
}
