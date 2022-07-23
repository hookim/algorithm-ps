// 21 12 27 백준1026번 보물 문제

#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N], b[N];
    for(int i =0; i<N; i++){
        cin >> a[i];
    }
    for(int i =0; i<N; i++){
        cin >> b[i];
    }

    for(int i = 1; i < N; i++){
        int temp;
        for(int j = i; j > 0; j--){
            if(a[j] < a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
            if (b[j] > b[j-1]){
                temp = b[j];
                b[j] = b[j-1];
                b[j-1] = temp;
            }
        }
    }
    int sum = 0;
    for(int i =0 ; i < N; i++){
        sum += (a[i] * b[i]);
    }
    cout << sum << endl;

    return 0;
}