//백준 1011번 Fly me to the Alpha Centauri 문제

#include<iostream>

using namespace std;

int main(void){
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        int x,y;
        cin >> x >> y;
        int dis = y-x;
        int k =1;
        int right, left;
        while(1){
            if(k * (k+1) < dis) k++;
            else if(k * (k+1) == dis){
                cout << 2*k << endl;
                break;
            }else{
                if(dis - (k-1) * k <= k){
                    cout << 2 * (k-1) + 1 << endl;
                    break;
                }else{
                    cout << 2 * k << endl;
                    break;
                }
            }
        }
    }

    return 0;
}