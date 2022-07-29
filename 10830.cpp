#include <iostream>

using namespace std;
void matmul(int** A , int** B, int ** C, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            C[i][j] = A[i][j] * B[j][i];
        }
    }
}
void mat_i(int N, int ){
    int res[5][5];
    for(int i = 0; i < N; i++){
        res[i][i] = 1;
    }
    return (int **) res;
} 
void pow(int** A, int N, int B){
    if(B == 0)
        return mat_i(N);
    else if (B % 2){
        int ** produce = pow(A, N, B -1);
        int C[N][N];
        matmul(A, produce, (int **) C, N);
        return 
    }
    else {
        int ** produce = pow(A, N , B/2);
        int C[N][N];
        matmul(produce, produce, (int **) C, N);
    }
}

int main(void){
    int N, B;
    int mat[5][5];
    cin >> N >> B;
    for(int i =0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mat[i][j];
        }
    }
    int ** ans = pow((int **) mat, N, B);

    for(int i =0; i < N ; i++){
        for (int j = 0; j < N ; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
