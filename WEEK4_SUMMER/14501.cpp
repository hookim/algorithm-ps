#include <iostream>

using namespace std;
void findMax(int day, int p, int N, int times[], int profit[], int &max){
    if(day == N){
        if (max < p)
            max = p ;
        return; 
    }
    findMax(day+1, p, N, times, profit, max);
    if(day+times[day] <= N)
        findMax(day + times[day], p + profit[day], N, times, profit, max);  
    // else{
    //     if(max < p)
    //         max = p;
    //     return;
    // }

}

int main(void){
    int times[15];
    int profit[15];
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i ++){
        cin >> times[i];
        cin >> profit[i];
    }
    int max = -1;
    findMax(0, 0, N, times, profit, max);
    cout << max << endl;

    return 0;
}
