//2021 12 19 백준 분해합 2231


#include<iostream>
using namespace std;
int subSum(int n){
    int sum = 0;
    while(n != 0){
        sum += n % 10;
        n = (int)(n/10);
    }
    return sum;
}

int main(void){
    int N, M = 0, isG = 0;
    cin >> N;

    while(!isG && M < N){
        M++;
        if(subSum(M) + M  ==  N) isG = 1;
        
    }

    if(isG) cout << M << endl;
    else cout << 0 << endl;

    return 0;
}