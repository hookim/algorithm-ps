#include <iostream>
#include <list>

using namespace std;

list<char> Q; 
int N, max_f, go_back;
char cmd[16];
char C;
int freq[26];


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
      scanf("%s", cmd);
      go_back = 0;
      if(cmd[0] == 'e'){
        scanf(" %c", &C);
        freq[C - 'A']++;
        Q.push_back(C);
      }
      else if(!Q.empty()){
        max_f = -1;
        for(int k = 0 ; k < 26; k++){
          if(freq[k] > max_f) max_f = freq[k];
        }
        while(freq[Q.front() - 'A'] != max_f){
          Q.push_back(Q.front());
          Q.pop_front();
          go_back++;
        }
        cout << Q.front()  << " ";
        freq[Q.front() - 'A']--;
        Q.pop_front();

        while(go_back--){
          Q.push_front(Q.back());
          Q.pop_back();
        }
      }
      else{
        cout << "* ";
      }
    }

    return 0;
}
