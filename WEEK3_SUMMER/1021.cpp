#include <deque>
#include <iostream>

using namespace std;

int main(void){
    int N ,P;
    cin >> N >> P;

    deque <int> q;
    
    for(int i = 0; i < N ; i++){
        q.push_back(i+1);
    }

    int k, ans =0;
    for(int i = 0; i < P; i ++){
        cin >> k;
        int cw = 0, counter_cw = 0;
        int og = q.front();

        while(q.front() != k){
            q.push_back(q.front());
            q.pop_front();
            cw ++;
        }
        while (q.front() != og){
            q.push_back(q.front());
            q.pop_front();
            counter_cw ++;
        }
        while(q.front() != k){
            q.push_back(q.front());
            q.pop_front();
        }
        ans += min(cw, counter_cw);
        q.pop_front();
    }

    cout << ans << endl;
    return 0;
}
