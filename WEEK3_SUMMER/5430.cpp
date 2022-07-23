#include <deque>
#include <iostream>

using namespace std;

int main(void){
    int T;
    cin >> T;

    for(int i =0 ; i < T ; i ++){
        deque <int> q;
        string str;
        int N, dir = 1, err = 0;
        cin >> str;
        cin >> N;

        string temp;
        cin >> temp;
        int idx = 1;
        
        string extract = "";
        while(N){
            char c = temp[idx++];
            if(c == ',' || c == ']'){
                N--;  
                q.push_back(stoi(extract));
                extract = "";
            } 
            else extract += c;
        }

    
        for(int j =0; j < str.size(); j ++){
            char cm = str[j];
            if(cm == 'R'){
                dir = (-dir); 
            }else if (cm == 'D'){
                if(q.empty()){
                    err =1;
                    break;
                }
                dir > 0 ? q.pop_front() : q.pop_back();
            }
        }
    
        if(err)
            printf("error\n");
        else if (q.empty())
            printf("[]\n");
        else{
            printf("[");
            if(dir > 0){
                while(q.size() > 1){
                    printf("%d,",q.front());
                    q.pop_front();
                }
                printf("%d]\n", q.front());
            }
            else{
                while(q.size() > 1){
                    printf("%d,", q.back());
                    q.pop_back();
                }
                printf("%d]\n", q.back());
            }
        }

    }
    return 0;
}
