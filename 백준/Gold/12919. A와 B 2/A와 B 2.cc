#include <iostream>
using namespace std;

bool ans;
string a, b;

void solve(int start, int end, bool dir){
    if(ans){
        return;
    }
    if(abs(end - start) + 1 == a.size()){
        for(int i = 0; i < a.size(); i++){
            if(a[i] !=  b[start + i *(dir? 1 : -1)]){
                return;
            }
        }
        ans = true;
        return;
    }

    if(b[end] == 'A'){
        solve(start, end + (dir ? -1 : 1), dir);
    }
    if(b[start] == 'B'){
        solve(end , start + (dir ? 1 : -1), !dir);
    }

}

int main(void){
    cin >> a >> b;

    solve(0, b.size() - 1, true);

    cout << ans << endl;

    return 0;
}