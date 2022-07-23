//21 12 25 백준 1012번 유기농 배추 문제


#include <iostream>

using namespace std;

void isGroup(int F[50][50], int M, int N, int x, int y){
    if( F[x][y] != 1 || x < 0 || y < 0 || x >= M || y >= N ) return;
    else{
        F[x][y] = -1;
        isGroup(F, M, N, x-1, y);
        isGroup(F, M, N, x+1, y);
        isGroup(F, M, N, x, y-1);
        isGroup(F, M, N, x, y+1);
        return;
    }
}


int main(){
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        int M,N,K;
        cin >> M >> N >> K;
        
        int F[50][50] = {0};
        int C[K][2];

        for(int i =0; i< K; i++){
            cin >> C[i][0] >> C[i][1];
            F[ C[i][0] ][ C[i][1] ] = 1;
        }
        int count = 0;
        for(int i = 0; i < K ; i++){
            if(F[ C[i][0] ][ C[i][1] ] == 1) {
                count ++;
                isGroup(F,M,N,C[i][0],C[i][1]);
            }
        }
    
        cout << count << endl;
    }

    return 0;

}