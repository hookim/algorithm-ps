#include <iostream>
#include <queue> 
#include <algorithm>

using namespace std;


int N, M;
int day[100][100], arr[100][100];
int dR[] = {0, 1, 0, -1};
int dC[] = {1, 0, -1, 0};
string row;

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            day[i][j] = 10000;
        }
    }
    day[0][0] = 1;
}

void bfs(){
    queue <pair<int, int>> q;

    init();

    q.push({0, 0});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int d = 0 ; d < 4 ; d++){
            int nR = r + dR[d];
            int nC = c + dC[d];

            if(nR < 0 || nR >= N || nC < 0 || nC >= M)
                continue;
            if(arr[nR][nC] == 0)
                continue;
            if(day[r][c] + 1 >= day[nR][nC])
                continue;
            
            day[nR][nC] = day[r][c] + 1;
            q.push({nR, nC});
        }
    }
}


int main(void){
    cin >> N >> M;
    for(int i = 0 ; i < N; i++){
        cin >> row;
        for(int j = 0; j < M; j++){
            arr[i][j] = row[j] - '0';
        }
    }

    bfs();
    cout << day[N-1][M-1] << "\n";

    return 0;
}

