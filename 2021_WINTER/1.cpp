#include <iostream>

using namespace std;
int main(void){
    int N;
    cin >> N;
    int * nums = new int(N);
    for (int i = 0; i < N; i++) {cin >> nums[i]; }

    int minIdx,temp;
    for(int j = 0; j < N-1 ; j++){
        minIdx = j;
        for(int k = j+1; k < N; k++){
            if(nums[minIdx] > nums[k]) minIdx = k;
            
        }
        temp = nums[minIdx];
        nums[minIdx] = nums[j];
        nums[j] = temp;
    }

    for (int i = 0; i < N; i++){
        cout << nums[i] << endl;
    }

    return 0;
}
