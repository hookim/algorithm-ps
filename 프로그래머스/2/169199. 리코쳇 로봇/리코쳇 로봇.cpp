#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

bool visited[100][100];
queue<tuple<int, int, int>> q;
int N, M, targetN, targetM;
vector<string> boards;

int dN[] = {0, 1, -1, 0};
int dM[] = {1, 0, 0, -1};

void move(int curN, int curM, int curD, int NN, int MM){
    int nextN = curN + NN;
    int nextM = curM + MM;
    
    while(1){
        if(nextN < 0 || nextN >= N || nextM < 0 || nextM >= M) {
            nextN -= NN;
            nextM -= MM;
            break;
        }
        
        if(boards[nextN][nextM] == 'D') {
            nextN -= NN;
            nextM -= MM;
            break;
        }
        nextN += NN;
        nextM += MM;
    }
    
    if(visited[nextM][nextN]) return;
    
    visited[nextM][nextN] = true;
    q.push(make_tuple(nextN, nextM, curD + 1));
    
    return;
}

int solution(vector<string> board) {
    int answer = -1;
    
    boards = board;
    
    N = board.size();
    M = board[0].length();
    
    for(int n = 0 ; n < N; n++){
        for(int m = 0 ; m < M ; m++){
            if(board[n][m] == 'G'){
                targetN = n; 
                targetM = m;
            }
            if(board[n][m] == 'R'){
                visited[n][m] = true;
                q.push(make_tuple(n, m, 0));
            }
        }
    }
    
    int curN, curM, curD;
    while(!q.empty()){
        tie(curN, curM, curD) = q.front();
        q.pop();
        if(curN == targetN && curM == targetM){
            answer = curD;
            break;
        }
        
        for(int d = 0; d < 4; d++){
            move(curN, curM, curD, dN[d], dM[d]);
        }
        
    }
    
    
    return answer;
}