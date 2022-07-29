#include <iostream>
#include <cmath>

using namespace std;
void zigzag(int y, int x, int size, int r, int c, int & ans){
    if (ans == -1)
        return;
    if(size == 1){
        ans++;
        if(y == r && x == c){
            cout << ans-1 << endl;
            ans = -1;
        }

        return;
    }
    int new_size = size / 2;
    zigzag(y, x , new_size, r, c, ans);
    zigzag(y, x + new_size , new_size, r, c, ans);
    zigzag(y + new_size, x , new_size, r, c, ans);
    zigzag(y + new_size, x + new_size , new_size, r, c, ans);
    
    return;
}

int main(void){
    int N, r, c;
    cin >> N >> r >> c;
    int ans = 0;
    zigzag(0, 0, (int)pow(2, N), r, c, ans);
    return 0;
}
