// 2021 12 21 백준 1002번 터렛 문제

#include<iostream>

using namespace std;

int pow (int x){
    return x * x;
}
int main(){
    int T,x1,x2,y1,y2,r1,r2;
    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if(x1 == x2 && y1 == y2){
            if(r1 == r2) cout << -1 << endl;
            else cout << 0 << endl;
        }else{
            double dd = pow(x1 - x2) + pow(y1 - y2);
            int rrSub = pow(r1 - r2);
            int rrSum = pow(r1 + r2);
            if(dd < rrSub) cout << 0 << endl;
            else if (dd == rrSub) cout << 1 << endl;
            else{
                if(rrSum == dd) cout << 1 <<endl;
                else if (rrSum < dd) cout << 0 << endl;
                else cout << 2 << endl;
            }             
        }
    }
    return 0;
}


