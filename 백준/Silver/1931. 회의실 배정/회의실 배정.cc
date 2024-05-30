#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int N, cnt, ltime;
vector<pair<int, int>> arr;

class comp{
public:
    bool operator() (const pair<int, int>& a, const pair<int, int>& b){
        if(a.second < b.second){
            return true;
        }
        else if(a.second > b.second){
            return false;
        }
        else if (a.first < b.first){
            return true;
        }
        else{
            return false;
        }

    }
};

int main(void){

    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int b, e;
        cin >> b >> e;
        arr.push_back({b, e});
    }

    comp cmp;

    sort(arr.begin(), arr.end(), cmp);
    
    for(int i = 0; i < arr.size(); i++){
        if(ltime > arr[i].first)
            continue;

        ltime = arr[i].second;
        cnt++;
    }

    cout << cnt << endl;



    return 0;
}

