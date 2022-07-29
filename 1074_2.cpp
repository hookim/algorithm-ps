#include <iostream>
#include <cmath>

using namespace std;
bool isInRange(int y, int x, int size, int r, int c){
    if(y <= r && r < y + size && x <= c && c < x + size)
        return true;
    else 
        return false;

}
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
    if(isInRange(y,x,new_size,r, c))
        zigzag(y, x , new_size, r, c, ans);
    else
        ans += new_size * new_size;

    if(isInRange(y, x + new_size , new_size, r, c))
        zigzag(y, x + new_size , new_size, r, c, ans);
    else
        ans += new_size * new_size;

    if(isInRange(y + new_size, x , new_size, r, c))
        zigzag(y + new_size, x , new_size, r, c, ans);
    else
        ans += new_size * new_size;
        
    if(isInRange(y + new_size, x + new_size , new_size, r, c))
        zigzag(y + new_size, x + new_size , new_size, r, c, ans);
    else
        ans += new_size * new_size;
    
    return;
}

int main(void){
    int N, r, c;
    cin >> N >> r >> c;
    int ans = 0;
    zigzag(0, 0, (int)pow(2, N), r, c, ans);
    return 0;
}
