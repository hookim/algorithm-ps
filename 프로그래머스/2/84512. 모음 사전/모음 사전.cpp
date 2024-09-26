#include <string>
#include <vector>

using namespace std;
/*
    dfs를 쓰라고 하는데? 
    
*/

vector <string>words;
char arr[] = {'A', 'E', 'I', 'O', 'U'};

void solve(string s){
    if(s.size() == 5){
        return;
    }
    
    for(char c : arr){
        words.push_back(s + c);
        solve(s + c);
    }
    
}

int solution(string word) {
    solve("");
    int answer = 0;
    for(string w : words){
        answer++;
        if(w == word){
            break;
        }
    }
    return answer;
}