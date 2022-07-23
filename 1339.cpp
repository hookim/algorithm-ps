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

    unordered_map <char, int> umap;
    char nums[10];
    for(int j = 0; j < 10 ; j++){
        for(int i = 0; i < N; i++){
            string cur = alp[i].second;
            if(j >= cur.length())
                continue;

            if(umap.find(cur[j]) == umap.end()){
                int idx = 9;
                for(; (int) nums[idx] != 0; idx--);
                nums[idx] = cur[j];
                umap[cur[j]] = idx;
                cur[j] = '0' + idx;
            }else
                cur[j] = '0' + umap[cur[j]];
        }
    }
    int ans =0;
    for(int i = 0; i < N; i++){
        ans += stoi(alp[i].second);
    }
    cout << ans << endl;

    return 0;
}
