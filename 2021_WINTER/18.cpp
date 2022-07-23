// 백준 4344번 above the average

#include <iostream>
#include <iomanip> 

using namespace std;

int main(void){
    int T;
    cin >> T;
    for (int t = 0 ; t < T; t++){
        int N;
        cin >> N;
        int scores[N];
        int avg =  0;
        for(int i = 0; i < N; i++){
            cin >> scores[i];
            avg += scores[i]; 
        }
        avg /= N;
        int count  = 0;
        for (int i = 0; i < N; i++){
            if(avg < scores[i]) count ++;
        }
        cout << fixed << setprecision(3) <<  (float)count / N * 100  << "%" <<  endl;
        
    }
    return 0;
}