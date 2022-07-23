#include <iostream>

using namespace std;
void placeBlock(int row, int col, int H, int W, bool bd[20][20], int &ans){
    if(col == W-1)
        placeBlock(row+1, 0, H, W, bd, ans);
    if(row == H-1){
        bool ok = true;
        for(int i = 0 ; i < W; i++){
            if(!bd[row][i]){
                ok = false;
                break;
            }
        }
        if(ok)
            ans++;
        return;
    }
    
    
}

int main(void){
    int C, H, W;
    cin >> C;
    for(int i =0 ; i < C; i++){
        bool bd[20][20] = {0};
        cin >> H >> W;
        for (int row =  0; row < H; row++){
            string temp_row;
            cin >> temp_row;
            for(int col = 0 ; col < (int)temp_row.size(); col++){
                if(temp_row[col] == '#')
                    bd[row][col] = 1;
            }
        }
        int ans = 0;
        placeBlock(0,0,H,W,bd,ans);
        cout << ans << '\n';
    }

    return 0;
}
