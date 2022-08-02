#include <iostream>
using namespace std;

bool can_i_fold(string& s, int begin, int end){
    if(begin == end)
        return true;
    if(s[begin] == s[end])
        return false;
    int mid = (begin + end)/2;

    return can_i_fold(s, begin, end -1) && can_i_fold(s, mid+1, end);
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
