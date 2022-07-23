//종만북 조세푸스 문제 

#include<iostream>
#include<list>

using namespace std;


int main(void){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int N,K;
        cin >> N >> K;
        list<int> l;
        for(int i = N; i >= 1; i--){
            l.push_front(i);
        }

        list<int>::iterator it = l.begin();

        for(int i = 0; i < N-2; i++){
            l.erase(it);
            for(int j =0; j < K; j++){
                it++;
                if(it == l.end()) it = l.begin();
            }
        } 

        it = l.begin();
        cout << *it << " " << *(++it) << endl;
        
    }
    return 0;
}
