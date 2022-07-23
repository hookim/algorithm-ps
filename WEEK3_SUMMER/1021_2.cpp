#include <stack>
#include <iostream>

using namespace std;

int main(void){
    int N, M, k;
    scanf("%d %d", &N, &M);
    deque <int> q;
    for (int i = 0; i < N; i++){
        q.push_back(i+1);
    }
    int ans = 0;
    for (int i = 0 ; i < M ; i++){
        scanf("%d" , &k);
        int cnt = 0;

        while(k != q.front()){
            q.push_back(q.front());
            q.pop_front();
            cnt++;
        }
        ans += (cnt < q.size() - cnt ? cnt :  q.size() - cnt);
        q.pop_front();

    }
    printf("%d\n", ans);

    return 0;
}
