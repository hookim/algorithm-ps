#include <iostream>

using namespace std;


void combiOp(int idx, int res, int nums[], int op[], int size, int * minN, int * maxN){
    if (idx == size-1){
        if (res < *minN) *minN = res;
        if (res > *maxN) *maxN = res;
        return;
    }

    if(op[0]){
        op[0]--;
        combiOp(idx+1, res+nums[idx+1] ,nums, op, size, minN, maxN);
        op[0]++;
    }
    if(op[1]){
        op[1]--;
        combiOp(idx+1, res-nums[idx+1], nums, op, size, minN, maxN);
        op[1]++;
    }
    if(op[2]){
        op[2]--;
        combiOp(idx+1, res * nums[idx+1], nums, op, size, minN, maxN); 
        op[2]++;
    }
    if(op[3]){
        op[3]--;
        combiOp(idx+1, (int)res / nums[idx+1] ,nums, op, size, minN, maxN); 
        op[3]++;
    }
}

int main(void){
    int n ;
    cin >> n;
    int nums[11] = {0};
    for(int i = 0 ; i < n ; i++){
        scanf("%d", nums + i);
    }
    int op[4] = {0};
    for(int i =0; i < 4 ; i++){
        scanf("%d", op + i);
    }
    int maxN = -1000000001, minN = 1000000001;
    combiOp(0, nums[0], nums, op, n, &minN, &maxN);

    cout << maxN << '\n';
    cout << minN << '\n';

    return 0;
}
