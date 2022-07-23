#include <iostream>
#include <list>

using namespace std;

int main(void){

    string s; 
    cin >> s;
    list <char> l(s.begin(), s.end()); 
    int N; 

    auto it = l.end();
    scanf("%d",&N);
    
    char cm, c;
    for(int i = 0; i < N ; i++){
        cin >> cm;
        if(cm == 'L'){
            if(it != l.begin())
                it--;
        }else if (cm == 'D'){
            if(it != l.end())
                it++;
        }else if (cm == 'B'){
            if(it != l.begin())
                l.erase(prev(it, 1));
        }else if (cm == 'P'){
            cin >> c;
            l.insert(it, c);
        }
    }

    for(it = l.begin() ; it != l.end() ; it++){
        printf("%c", *it);
    }
    printf("\n");
    return 0;
}
