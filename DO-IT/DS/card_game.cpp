#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, i;
    queue<int> Q;

    cin >> N;
    for(i = 1; i <= N; i++){
      Q.push(i);
    }

    while(Q.size() > 1){
      Q.pop();
      Q.push(Q.front());
      Q.pop();
    }

    cout << Q.front() << endl;

    return 0;
}
