#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> L;
priority_queue<int, vector<int>, greater<int>> R;

int N, a, median;

int main (void){
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> N;
    cin >> a;
    R.push(a);
    median = a;
    cout << median << "\n";
    for(int i = 1; i < N ; i++){
        cin >> a;
        if(a >= median){
            R.push(a);
        }
        else{
            L.push(a);
        }

        if(R.size() - L.size() > 1){
            L.push(R.top());
            R.pop();
        }

        while(L.size() > R.size()){
            R.push(L.top());
            L.pop();
        }

        if(R.size() == L.size())
            median = L.top();
        else
            median = R.top();

        cout << median << "\n";
    }


    return 0;
}