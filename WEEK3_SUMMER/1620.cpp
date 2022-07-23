#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    map <string, int> by_name;
    vector <string> by_idx;

    int N, M;
    cin >> N >> M;
    string s;
    for(int i =0 ; i < N; i++){
        cin >> s;
        by_name[s] = i+1;
        by_idx.push_back(s);

    }

    for(int i = 0; i < M ; i++){
        cin >> s;
        if (isdigit(s[0]))
            cout << by_idx[stoi(s) - 1] << '\n';
        else
            cout << by_name[s] << '\n';
    }

    return 0;
}
