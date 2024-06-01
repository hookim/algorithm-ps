#include <iostream>
#include <vector> 
#include <algorithm>

#define MAX 1000000000

using namespace std;

int N, a, ans = MAX;
bool zflag;
vector<int> arr;

void search(int n){
    int beg = 0, end = N-1;
    
    while(beg < end){
        if(arr[beg] < 0){
            beg++;
            continue;
        }
        if(arr[end] < 0){
            end--;
            continue;
        }

        int snowman = arr[beg] + arr[end];

        if(snowman - n < 0){
            beg++;
        }
        else if(snowman - n > 0){
            end--;
        }
        else{
            zflag = true;
            return;
        }

        ans = min(ans, abs(n - snowman));
    }
}

void solve(){ 
    int tempA, tempB;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            tempA = arr[i];
            tempB = arr[j];

            arr[i] = -1;
            arr[j] = -1;

            search(tempA + tempB);

            if(zflag){
                return;
            }

            arr[i] = tempA;
            arr[j] = tempB;
        }
    }
}

int main(void){

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    solve();
    if(zflag){
        cout << 0 << endl;
    }
    else{
        cout << ans << endl;
    }

    return 0;
}

