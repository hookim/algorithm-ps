// 21 12 26 백준 1024 번 수열의 합 문제

#include<iostream>
using namespace std;

int main(){
    int n, l;
    cin >> n >> l;
    
    int sum;
    int no = 1;
    for(;l<=100; l++){
        sum = l * (l-1) / 2;
        if(n >= sum && (n - sum) % l == 0){
            no = 0;
            break; 
        }
    }
    if(!no){
        int dis = (n - sum) / l;
        for(int i = 0; i < l; i++){
            cout << i + dis << " ";
        }
    }else 
        cout << -1;
    cout << endl;
    
    return 0;
}


