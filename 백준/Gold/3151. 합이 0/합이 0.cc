#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int N, num;
long long ans;
vector<int> arr;
int counts[20002];

void searchComb(int i){
    int beg = i + 1, end = arr.size()-1;
    
    while(beg < end){
        int n = arr[beg] + arr[end] + arr[i];

        if(n > 0){
            end--;
        }
        else if(n < 0){
            beg++;
        }
        else {
            if (arr[beg] == arr[end]){
                ans += (end - beg);
            }
            else{
                ans += (counts[arr[end] + 10000]);
            }
            beg++;
        }
    } 
}


void solve(){
    for(int i  = 0; i < arr.size(); i++){
        if(arr[i] > 0){
            return;
        }
        searchComb(i);
    }
}

int main(void){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        
        arr.push_back(num);
        counts[num + 10000]++;
        
    }

    sort(arr.begin(), arr.end());
    solve();

    cout << ans << endl;

    return 0;
}

