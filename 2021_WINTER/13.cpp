// 21 12 26 백준 1010번 다리놓기 문제


#include<iostream>
using namespace std;

int main(void){
    int T, N, M;
    cin >> T;
    for(int k =0 ; k < T ; k++){
        cin >> N >> M;
        int table [N][M];
        for(int i = 0; i < N; i++){
            for(int j = i; j < M; j++){
                if(i==j) table[i][j] = 1;
                else if(i == 0) table[i][j] = j+1;
                else table[i][j] = table[i-1][j-1] + table[i][j-1];
            }
        }
        cout << table[N-1][M-1] << endl;
    }
    
    return 0;

}