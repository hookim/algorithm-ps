#include <iostream>

using namespace std;

int main(void){
    int N;
    string S;
    cin >> N >> S;

    int sum = 0;
    for(int i = 0 ; i < S.length(); i++){
      sum += (S[i] - '0');
    }

    cout << sum << "\n";

    return 0;
}
