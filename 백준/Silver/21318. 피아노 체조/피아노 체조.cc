#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int a, b, N, Q;
int arr[100001], ss[100001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    int s = 0;
    for(int i = 2; i <= N; i++){
        if(arr[i-1] > arr[i]){
            s ++;
        }
        ss[i] = s;
    }

    cin >> Q;

    for(int i = 0; i < Q; i++){
        cin >> a >> b;
        cout << ss[b] -ss[a] << "\n"; 
    }

    return 0;
}