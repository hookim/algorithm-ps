//2021 12 23 백준 1009 번 분산처리 문제

#include<iostream>
using namespace std;

int main(void){
    int T;
    cin >> T;
    
    for(int i = 0 ; i < T; i++){
        int a,b;
        cin >> a >> b;
        int lD = a%10; 

        switch(lD){
            case 1:case 5:case 6:
                cout << lD << endl;
                break;
            case 4: case 9:
                if(b % 2) cout << lD << endl;
                else cout << (lD*lD) % 10 << endl;
                break;
            case 2: case 3: case 7: case 8:
                if(b % 4 == 1) cout << lD <<endl;
                else if (b % 4 == 2) cout << (lD*lD)%10 << endl;
                else if (b % 4 == 3) cout << (lD*lD*lD)%10 << endl;
                else cout << (lD*lD*lD*lD)%10 << endl;
                break;
            default:
                cout << 10 << endl;
                break;
        }        
    }
    return 0;
}