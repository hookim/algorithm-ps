#include <iostream>
#include <queue>

using namespace std;
int matchPlayer(queue <int> &rus, queue <int> &kor){
    if(rus.empty()){
        return 0;
    }
    int opp = rus.front();
    int lclMinPos = 0, glbMinPos = 0, lclMin = 4001, glbMin = 4001;
    for(int i = 0; i < kor.size(); i++){
        int cur = kor.front();
        if(opp <= cur && lclMin > cur){
            lclMinPos = i;
            lclMin = cur;
        }
        if(glbMin > cur){
            glbMinPos = i;
            glbMin = cur;
        }
        kor.push(kor.front());
        kor.pop();
    }
    rus.pop();
    if(lclMin != 4001){
        for(int i = 0; i < lclMinPos; i++){
            kor.push(kor.front());
            kor.pop();
        }
        kor.pop();
        return 1 + matchPlayer(rus, kor);
    }

    for(int i = 0; i < glbMinPos; i++){
        kor.push(kor.front());
        kor.pop();
    }
    kor.pop();
    return matchPlayer(rus, kor);
}

int main(void){
    int T;
    cin >> T;
    for(int cases = 0 ; cases < T; cases++){
        int C; 
        cin >> C;
        queue <int> rus;
        int rating;
        for(int i = 0; i < C; i++){
            cin >> rating;
            rus.push(rating);
        }
        queue <int> kor;
        for(int i = 0; i < C; i++){
            cin >> rating;
            kor.push(rating);
        }

        int ans = matchPlayer(rus, kor);
        cout << ans << endl;

    }
    return 0;
}
