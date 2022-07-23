//2021 12 20 백준 1018번 문제 체스판 다시 칠하기 
#include<iostream>
#include<string>

using namespace std;

int main(){
    int N, M ;
    cin >> N >> M;
    string board[N];
    for(int i = 0; i < N; i++){
        cin >> board[i];
    }

    int fwCount = 0, fbCount = 0, min = 9999999;
    int fWhiteW = 1;
    for(int x = 0, y = 0 ; y + 7 < N ; x++){
        fwCount = 0, fbCount = 0, fWhiteW =1;

        for(int i = y; i < y + 8; i++){
            for(int j = x; j < x + 8; j++){
                if(board[i][j] == 'W'){
                    if(fWhiteW != 1) fwCount++;
                    if(fWhiteW == 1) fbCount++;
                }else{
                    if(fWhiteW == 1) fwCount++;
                    if(fWhiteW != 1) fbCount++;
                }
                fWhiteW = (fWhiteW == 0);
            }
            fWhiteW = (fWhiteW == 0);    
        }
        if(min > fwCount && fwCount <= fbCount ) min = fwCount;
        else if (min > fbCount && fwCount > fbCount ) min = fbCount;
        else ; 
        
        if(x + 7 == M - 1 ){
            x = -1;
            y++;
        }
    }
    
cout << min << endl;

return 0;
}