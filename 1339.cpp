#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int main(void){
    vector <pair <int , string> > alp;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        alp.push_back(make_pair(-s.size(), s));
    }

    sort(alp.begin(), alp.end());

    vector <string> strs;
    for(int i = 0; i < N; i++){
        string s (8, '0');
        strs.push_back(s);
        int max_size = alp[i].second.size();
        for(int j = 0; j < max_size; j++){
            strs[i][8 - max_size + j] = alp[i].second[j];
        }
    }

    unordered_map <char, int> chars_mapping;
    int n = 9;

    for(int col = 0 ; col < 8; col++){
        for(int row = 0; row < N; row++){
            if (strs[row][col] == '0')
                continue;
            else 
                if (chars_mapping.find(strs[row][col]) == chars_mapping.end()){
                    chars_mapping[strs[row][col]] = n;
                    strs[row][col] = '0' + (n--);
                }
                else{
                    strs[row][col] = '0' + chars_mapping[strs[row][col]];
                }
        }
    }
    int ans= 0;
    for(int i = 0; i < N; i++){
        ans += stoi(strs[i]);
    }

    cout << ans << endl;

    return 0;
}
