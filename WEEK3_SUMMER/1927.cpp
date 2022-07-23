#include <queue>
#include <iostream>

using namespace std;

int main(void){
    priority_queue <int, vector<int>, greater<int> > pq;
    int N, k;
    cin >> N;

    for(int i =0 ; i < N ; i++){
        scanf("%d", &k);
        if (k)
            pq.push(k);
        else if (pq.empty())
            printf("0\n");
        else{
            printf("%d\n", pq.top());
            pq.pop();
        }
    }

    return 0;
}
