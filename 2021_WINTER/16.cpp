//21 12 30 백준 1158번 요세푸스 문제

#include<iostream>
#include<list>

using namespace std;

int main(void){
    int N, K;
    cin >> N >> K;
    list<int> l;
    for(int i = 0; i < N; i++){
        l.push_back(i+1);
    }
    list<int>::iterator it = l.begin();
    for(int i =0; i < K-1; i++){
        it++;
    }
    cout << "<";
    for(int i = 0; i < N; i++){
        cout << *it;
        it = l.erase(it);
        if(it == l.end()) it = l.begin();
        for(int j = 0; j < K-1; j++){
            if((++it) == l.end()) it = l.begin();
        }
        if(i != N-1) cout << ", ";
    }cout<< ">" <<endl;

    return 0;
} 